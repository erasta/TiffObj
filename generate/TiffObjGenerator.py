import urllib.request, os
import CppHeaderParser

# target_url = 'https://gitlab.com/libtiff/libtiff/-/raw/master/libtiff/tiffio.h'
target_url = 'https://gitlab.com/libtiff/libtiff/-/raw/v4.0.9/libtiff/tiffio.h'
# filename = os.path.basename(target_url)
# print(filename)
lines = [line.decode('utf-8') for line in urllib.request.urlopen(target_url)]
text = ''.join(lines)
# with open(filename, 'w') as f:
#   for line in urllib.request.urlopen(target_url):
#     f.write(line.decode('utf-8'))

# header = CppHeaderParser.CppHeader(filename)
header = CppHeaderParser.CppHeader(text, "string")

def get_param(p, pind):
  ptype = p['type']
  pname = p['name']
  if ptype == '':
    ptype = pname
    pname = ''
  if pname == '' and ptype != 'va_list':
    pname = 'p' + str(pind)
  parray = None
  if p['array']:
    parray = 0
    if 'array_size' in p:
      parray = p['array_size']
  return ptype, pname, parray

def weird_param(p):
  if p['type'] != '' and p['type'][0] == ')':
    return True
  if p['name'] != '' and p['name'][0] == ')':
    return True
  return False

def is_weird_func(f):
  return len([p for p in f['parameters'] if weird_param(p)]) > 0

def gen_params_definitions(params):
  for pind, p in enumerate(params):
    if pind > 0:
      print(', ', end='')

    ptype, pname, parray = get_param(p, pind)

    print(ptype + ' ' + pname, end='')
    if (parray is not None):
      if parray == 0:
        print('[]', end='')
      else:
        print('[' + str(parray) + ']', end='')

def gen_params_passing(params, had_prev_params = True):
  for pind, p in enumerate(params):
    ptype, pname, parray = get_param(p, pind)
    if (pname != ''):
      if had_prev_params or pind > 0:
        print(', ', end='')
      print(pname, end='')

def gen_use_tif_func(f):
  print('    ', end='')
  funcname = f['name'][4:]
  print(f['rtnType'] + ' ' + funcname + '(', end='')
  gen_params_definitions(f['parameters'][1:])
  print(') {')
  if (f['rtnType'] == 'void'):
    print('        ', end='')
  else:
    print('        return ', end='')
  print(f['name'] + '(tif', end='')
  gen_params_passing(f['parameters'][1:])
  print(');')
  print('    }')

def gen_create_tif_func(f):
  print('    ', end='')
  funcname = f['name'][4:]
  print('TiffObj& ' + funcname + '(', end='')
  gen_params_definitions(f['parameters'])
  print(') {')
  print('        Close();')
  print('        tif = ', end='')
  print(f['name'] + '(', end='')
  gen_params_passing(f['parameters'], False)
  print(');')
  print('        return *this;')
  print('    }')

print('#ifndef __TIFF_OBJ__H__')
print('#define __TIFF_OBJ__H__')
print()
print('#include <tiffio.h>')
print()
print('class TiffObj')
print('{')
print('public:')
print('    TIFF * tif = 0;')
print()
print('    virtual ~TiffObj() {')
print('        Close();')
print('    }')
print('    void Close() {');
print('        if (tif != 0) {');
print('            TIFFClose(tif);');
print('            tif = 0;');
print('        }');
print('    }');

print()

functions = [f for f in header.functions if not is_weird_func(f)]

constructors_prefixes = ['TIFFOpen', 'TIFFFdOpen', 'TIFFClientOpen']

mutators = []
constructors = []
for f in functions:
  if f['name'].startswith('TIFF') and \
      len(f['parameters']) > 0 and \
      f['parameters'][0]['type'] == 'TIFF *' and \
      f['name'] != 'TIFFClose':
    mutators.append(f)
  elif f['rtnType'] == 'TIFF *' and \
      any(f['name'].startswith(prefix) for prefix in constructors_prefixes):
    constructors.append(f)

for f in constructors:
    gen_create_tif_func(f)

for f in mutators:
    gen_use_tif_func(f)

print('};')
print()
print('#endif /* __TIFF_OBJ__H__ */')
