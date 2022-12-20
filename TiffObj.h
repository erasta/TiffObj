#ifndef __TIFF_OBJ__H__
#define __TIFF_OBJ__H__

class TiffObj
{
public:
    TIFF * tif = 0;

    virtual ~TiffObj() {
        Close();
    }
    void Close() {
        if (tif != 0) {
            TIFFClose(tif);
            tif = 0;
        }
    }

    TiffObj& Open(const char * p0, const char * p1) {
        Close();
        tif = TIFFOpen(p0, p1);
        return *this;
    }
    TiffObj& OpenExt(const char * p0, const char * p1, TIFFOpenOptions * opts) {
        Close();
        tif = TIFFOpenExt(p0, p1, opts);
        return *this;
    }
    TiffObj& OpenW(const wchar_t * p0, const char * p1) {
        Close();
        tif = TIFFOpenW(p0, p1);
        return *this;
    }
    TiffObj& OpenWExt(const wchar_t * p0, const char * p1, TIFFOpenOptions * opts) {
        Close();
        tif = TIFFOpenWExt(p0, p1, opts);
        return *this;
    }
    TiffObj& FdOpen(int p0, const char * p1, const char * p2) {
        Close();
        tif = TIFFFdOpen(p0, p1, p2);
        return *this;
    }
    TiffObj& FdOpenExt(int p0, const char * p1, const char * p2, TIFFOpenOptions * opts) {
        Close();
        tif = TIFFFdOpenExt(p0, p1, p2, opts);
        return *this;
    }
    TiffObj& ClientOpen(const char * p0, const char * p1, thandle_t p2, TIFFReadWriteProc p3, TIFFReadWriteProc p4, TIFFSeekProc p5, TIFFCloseProc p6, TIFFSizeProc p7, TIFFMapFileProc p8, TIFFUnmapFileProc p9) {
        Close();
        tif = TIFFClientOpen(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        return *this;
    }
    TiffObj& ClientOpenExt(const char * p0, const char * p1, thandle_t p2, TIFFReadWriteProc p3, TIFFReadWriteProc p4, TIFFSeekProc p5, TIFFCloseProc p6, TIFFSizeProc p7, TIFFMapFileProc p8, TIFFUnmapFileProc p9, TIFFOpenOptions * opts) {
        Close();
        tif = TIFFClientOpenExt(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, opts);
        return *this;
    }
    int GetTagListCount() {
        return TIFFGetTagListCount(tif);
    }
    uint32_t GetTagListEntry(int tag_index) {
        return TIFFGetTagListEntry(tif, tag_index);
    }
    const TIFFField * FindField(uint32_t p0, TIFFDataType p1) {
        return TIFFFindField(tif, p0, p1);
    }
    const TIFFField * FieldWithTag(uint32_t p0) {
        return TIFFFieldWithTag(tif, p0);
    }
    const TIFFField * FieldWithName(const char * p0) {
        return TIFFFieldWithName(tif, p0);
    }
    TIFFTagMethods * AccessTagMethods() {
        return TIFFAccessTagMethods(tif);
    }
    void * GetClientInfo(const char * p0) {
        return TIFFGetClientInfo(tif, p0);
    }
    void SetClientInfo(void * p0, const char * p1) {
        TIFFSetClientInfo(tif, p0, p1);
    }
    void Cleanup() {
        TIFFCleanup(tif);
    }
    int Flush() {
        return TIFFFlush(tif);
    }
    int FlushData() {
        return TIFFFlushData(tif);
    }
    int GetField(uint32_t tag) {
        return TIFFGetField(tif, tag);
    }
    int VGetField(uint32_t tag, va_list ap) {
        return TIFFVGetField(tif, tag, ap);
    }
    int GetFieldDefaulted(uint32_t tag) {
        return TIFFGetFieldDefaulted(tif, tag);
    }
    int VGetFieldDefaulted(uint32_t tag, va_list ap) {
        return TIFFVGetFieldDefaulted(tif, tag, ap);
    }
    int ReadDirectory() {
        return TIFFReadDirectory(tif);
    }
    int ReadCustomDirectory(toff_t diroff, const TIFFFieldArray * infoarray) {
        return TIFFReadCustomDirectory(tif, diroff, infoarray);
    }
    int ReadEXIFDirectory(toff_t diroff) {
        return TIFFReadEXIFDirectory(tif, diroff);
    }
    int ReadGPSDirectory(toff_t diroff) {
        return TIFFReadGPSDirectory(tif, diroff);
    }
    uint64_t ScanlineSize64() {
        return TIFFScanlineSize64(tif);
    }
    tmsize_t ScanlineSize() {
        return TIFFScanlineSize(tif);
    }
    uint64_t RasterScanlineSize64() {
        return TIFFRasterScanlineSize64(tif);
    }
    tmsize_t RasterScanlineSize() {
        return TIFFRasterScanlineSize(tif);
    }
    uint64_t StripSize64() {
        return TIFFStripSize64(tif);
    }
    tmsize_t StripSize() {
        return TIFFStripSize(tif);
    }
    uint64_t RawStripSize64(uint32_t strip) {
        return TIFFRawStripSize64(tif, strip);
    }
    tmsize_t RawStripSize(uint32_t strip) {
        return TIFFRawStripSize(tif, strip);
    }
    uint64_t VStripSize64(uint32_t nrows) {
        return TIFFVStripSize64(tif, nrows);
    }
    tmsize_t VStripSize(uint32_t nrows) {
        return TIFFVStripSize(tif, nrows);
    }
    uint64_t TileRowSize64() {
        return TIFFTileRowSize64(tif);
    }
    tmsize_t TileRowSize() {
        return TIFFTileRowSize(tif);
    }
    uint64_t TileSize64() {
        return TIFFTileSize64(tif);
    }
    tmsize_t TileSize() {
        return TIFFTileSize(tif);
    }
    uint64_t VTileSize64(uint32_t nrows) {
        return TIFFVTileSize64(tif, nrows);
    }
    tmsize_t VTileSize(uint32_t nrows) {
        return TIFFVTileSize(tif, nrows);
    }
    uint32_t DefaultStripSize(uint32_t request) {
        return TIFFDefaultStripSize(tif, request);
    }
    void DefaultTileSize(uint32_t * p0, uint32_t * p1) {
        TIFFDefaultTileSize(tif, p0, p1);
    }
    int Fileno() {
        return TIFFFileno(tif);
    }
    int SetFileno(int p0) {
        return TIFFSetFileno(tif, p0);
    }
    thandle_t Clientdata() {
        return TIFFClientdata(tif);
    }
    thandle_t SetClientdata(thandle_t p0) {
        return TIFFSetClientdata(tif, p0);
    }
    int GetMode() {
        return TIFFGetMode(tif);
    }
    int SetMode(int p0) {
        return TIFFSetMode(tif, p0);
    }
    int IsTiled() {
        return TIFFIsTiled(tif);
    }
    int IsByteSwapped() {
        return TIFFIsByteSwapped(tif);
    }
    int IsUpSampled() {
        return TIFFIsUpSampled(tif);
    }
    int IsMSB2LSB() {
        return TIFFIsMSB2LSB(tif);
    }
    int IsBigEndian() {
        return TIFFIsBigEndian(tif);
    }
    int IsBigTIFF() {
        return TIFFIsBigTIFF(tif);
    }
    TIFFReadWriteProc GetReadProc() {
        return TIFFGetReadProc(tif);
    }
    TIFFReadWriteProc GetWriteProc() {
        return TIFFGetWriteProc(tif);
    }
    TIFFSeekProc GetSeekProc() {
        return TIFFGetSeekProc(tif);
    }
    TIFFCloseProc GetCloseProc() {
        return TIFFGetCloseProc(tif);
    }
    TIFFSizeProc GetSizeProc() {
        return TIFFGetSizeProc(tif);
    }
    TIFFMapFileProc GetMapFileProc() {
        return TIFFGetMapFileProc(tif);
    }
    TIFFUnmapFileProc GetUnmapFileProc() {
        return TIFFGetUnmapFileProc(tif);
    }
    uint32_t CurrentRow() {
        return TIFFCurrentRow(tif);
    }
    tdir_t CurrentDirectory() {
        return TIFFCurrentDirectory(tif);
    }
    tdir_t NumberOfDirectories() {
        return TIFFNumberOfDirectories(tif);
    }
    uint64_t CurrentDirOffset() {
        return TIFFCurrentDirOffset(tif);
    }
    uint32_t CurrentStrip() {
        return TIFFCurrentStrip(tif);
    }
    uint32_t CurrentTile() {
        return TIFFCurrentTile(tif);
    }
    int ReadBufferSetup(void * bp, tmsize_t size) {
        return TIFFReadBufferSetup(tif, bp, size);
    }
    int WriteBufferSetup(void * bp, tmsize_t size) {
        return TIFFWriteBufferSetup(tif, bp, size);
    }
    int SetupStrips() {
        return TIFFSetupStrips(tif);
    }
    int WriteCheck(int p0, const char * p1) {
        return TIFFWriteCheck(tif, p0, p1);
    }
    void FreeDirectory() {
        TIFFFreeDirectory(tif);
    }
    int CreateDirectory() {
        return TIFFCreateDirectory(tif);
    }
    int CreateCustomDirectory(const TIFFFieldArray * p0) {
        return TIFFCreateCustomDirectory(tif, p0);
    }
    int CreateEXIFDirectory() {
        return TIFFCreateEXIFDirectory(tif);
    }
    int CreateGPSDirectory() {
        return TIFFCreateGPSDirectory(tif);
    }
    int LastDirectory() {
        return TIFFLastDirectory(tif);
    }
    int SetDirectory(tdir_t p0) {
        return TIFFSetDirectory(tif, p0);
    }
    int SetSubDirectory(uint64_t p0) {
        return TIFFSetSubDirectory(tif, p0);
    }
    int UnlinkDirectory(tdir_t p0) {
        return TIFFUnlinkDirectory(tif, p0);
    }
    int SetField(uint32_t p0) {
        return TIFFSetField(tif, p0);
    }
    int VSetField(uint32_t p0, va_list ) {
        return TIFFVSetField(tif, p0);
    }
    int UnsetField(uint32_t p0) {
        return TIFFUnsetField(tif, p0);
    }
    int WriteDirectory() {
        return TIFFWriteDirectory(tif);
    }
    int WriteCustomDirectory(uint64_t * p0) {
        return TIFFWriteCustomDirectory(tif, p0);
    }
    int CheckpointDirectory() {
        return TIFFCheckpointDirectory(tif);
    }
    int RewriteDirectory() {
        return TIFFRewriteDirectory(tif);
    }
    int DeferStrileArrayWriting() {
        return TIFFDeferStrileArrayWriting(tif);
    }
    int ForceStrileArrayWriting() {
        return TIFFForceStrileArrayWriting(tif);
    }
    void PrintDirectory(FILE * p0, long p1) {
        TIFFPrintDirectory(tif, p0, p1);
    }
    int ReadScanline(void * buf, uint32_t row, uint16_t sample) {
        return TIFFReadScanline(tif, buf, row, sample);
    }
    int WriteScanline(void * buf, uint32_t row, uint16_t sample) {
        return TIFFWriteScanline(tif, buf, row, sample);
    }
    int ReadRGBAImage(uint32_t p0, uint32_t p1, uint32_t * p2, int p3) {
        return TIFFReadRGBAImage(tif, p0, p1, p2, p3);
    }
    int ReadRGBAImageOriented(uint32_t p0, uint32_t p1, uint32_t * p2, int p3, int p4) {
        return TIFFReadRGBAImageOriented(tif, p0, p1, p2, p3, p4);
    }
    void PrintDirectory(FILE * p0, long p1) {
        TIFFPrintDirectory(tif, p0, p1);
    }
    int ReadScanline(void * buf, uint32_t row, uint16_t sample) {
        return TIFFReadScanline(tif, buf, row, sample);
    }
    int WriteScanline(void * buf, uint32_t row, uint16_t sample) {
        return TIFFWriteScanline(tif, buf, row, sample);
    }
    int ReadRGBAImage(uint32_t p0, uint32_t p1, uint32_t * p2, int p3) {
        return TIFFReadRGBAImage(tif, p0, p1, p2, p3);
    }
    int ReadRGBAImageOriented(uint32_t p0, uint32_t p1, uint32_t * p2, int p3, int p4) {
        return TIFFReadRGBAImageOriented(tif, p0, p1, p2, p3, p4);
    }
    int ReadRGBAStrip(uint32_t p0, uint32_t * p1) {
        return TIFFReadRGBAStrip(tif, p0, p1);
    }
    int ReadRGBATile(uint32_t p0, uint32_t p1, uint32_t * p2) {
        return TIFFReadRGBATile(tif, p0, p1, p2);
    }
    int ReadRGBAStripExt(uint32_t p0, uint32_t * p1, int stop_on_error) {
        return TIFFReadRGBAStripExt(tif, p0, p1, stop_on_error);
    }
    int ReadRGBATileExt(uint32_t p0, uint32_t p1, uint32_t * p2, int stop_on_error) {
        return TIFFReadRGBATileExt(tif, p0, p1, p2, stop_on_error);
    }
    int RGBAImageOK(char p0[1024]) {
        return TIFFRGBAImageOK(tif, p0);
    }
    const char * FileName() {
        return TIFFFileName(tif);
    }
    const char * SetFileName(const char * p0) {
        return TIFFSetFileName(tif, p0);
    }
    uint32_t ComputeTile(uint32_t x, uint32_t y, uint32_t z, uint16_t s) {
        return TIFFComputeTile(tif, x, y, z, s);
    }
    int CheckTile(uint32_t x, uint32_t y, uint32_t z, uint16_t s) {
        return TIFFCheckTile(tif, x, y, z, s);
    }
    uint32_t NumberOfTiles() {
        return TIFFNumberOfTiles(tif);
    }
    tmsize_t ReadTile(void * buf, uint32_t x, uint32_t y, uint32_t z, uint16_t s) {
        return TIFFReadTile(tif, buf, x, y, z, s);
    }
    tmsize_t WriteTile(void * buf, uint32_t x, uint32_t y, uint32_t z, uint16_t s) {
        return TIFFWriteTile(tif, buf, x, y, z, s);
    }
    uint32_t ComputeStrip(uint32_t p0, uint16_t p1) {
        return TIFFComputeStrip(tif, p0, p1);
    }
    uint32_t NumberOfStrips() {
        return TIFFNumberOfStrips(tif);
    }
    tmsize_t ReadEncodedStrip(uint32_t strip, void * buf, tmsize_t size) {
        return TIFFReadEncodedStrip(tif, strip, buf, size);
    }
    tmsize_t ReadRawStrip(uint32_t strip, void * buf, tmsize_t size) {
        return TIFFReadRawStrip(tif, strip, buf, size);
    }
    tmsize_t ReadEncodedTile(uint32_t tile, void * buf, tmsize_t size) {
        return TIFFReadEncodedTile(tif, tile, buf, size);
    }
    tmsize_t ReadRawTile(uint32_t tile, void * buf, tmsize_t size) {
        return TIFFReadRawTile(tif, tile, buf, size);
    }
    int ReadFromUserBuffer(uint32_t strile, void * inbuf, tmsize_t insize, void * outbuf, tmsize_t outsize) {
        return TIFFReadFromUserBuffer(tif, strile, inbuf, insize, outbuf, outsize);
    }
    tmsize_t WriteEncodedStrip(uint32_t strip, void * data, tmsize_t cc) {
        return TIFFWriteEncodedStrip(tif, strip, data, cc);
    }
    tmsize_t WriteRawStrip(uint32_t strip, void * data, tmsize_t cc) {
        return TIFFWriteRawStrip(tif, strip, data, cc);
    }
    tmsize_t WriteEncodedTile(uint32_t tile, void * data, tmsize_t cc) {
        return TIFFWriteEncodedTile(tif, tile, data, cc);
    }
    tmsize_t WriteRawTile(uint32_t tile, void * data, tmsize_t cc) {
        return TIFFWriteRawTile(tif, tile, data, cc);
    }
    void SetWriteOffset(toff_t off) {
        TIFFSetWriteOffset(tif, off);
    }
    uint64_t GetStrileOffset(uint32_t strile) {
        return TIFFGetStrileOffset(tif, strile);
    }
    uint64_t GetStrileByteCount(uint32_t strile) {
        return TIFFGetStrileByteCount(tif, strile);
    }
    uint64_t GetStrileOffsetWithErr(uint32_t strile, int * pbErr) {
        return TIFFGetStrileOffsetWithErr(tif, strile, pbErr);
    }
    uint64_t GetStrileByteCountWithErr(uint32_t strile, int * pbErr) {
        return TIFFGetStrileByteCountWithErr(tif, strile, pbErr);
    }
    int MergeFieldInfo(const TIFFFieldInfo[], uint32_t p1) {
        return TIFFMergeFieldInfo(tif, TIFFFieldInfo, p1);
    }
};

#endif /* __TIFF_OBJ__H__ */
