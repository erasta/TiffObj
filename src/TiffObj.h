#ifndef __TIFF_OBJ__H__
#define __TIFF_OBJ__H__

#include <tiffio.h>

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
    TiffObj& OpenW(const wchar_t * p0, const char * p1) {
        Close();
        tif = TIFFOpenW(p0, p1);
        return *this;
    }
    TiffObj& FdOpen(int p0, const char * p1, const char * p2) {
        Close();
        tif = TIFFFdOpen(p0, p1, p2);
        return *this;
    }
    TiffObj& ClientOpen(const char * p0, const char * p1, thandle_t p2, TIFFReadWriteProc p3, TIFFReadWriteProc p4, TIFFSeekProc p5, TIFFCloseProc p6, TIFFSizeProc p7, TIFFMapFileProc p8, TIFFUnmapFileProc p9) {
        Close();
        tif = TIFFClientOpen(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        return *this;
    }
    int GetTagListCount() {
        return TIFFGetTagListCount(tif);
    }
    uint32 GetTagListEntry(int tag_index) {
        return TIFFGetTagListEntry(tif, tag_index);
    }
    const TIFFField * FindField(unsigned int p0, TIFFDataType p1) {
        return TIFFFindField(tif, p0, p1);
    }
    const TIFFField * FieldWithTag(unsigned int p0) {
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
    int GetField(unsigned int tag) {
        return TIFFGetField(tif, tag);
    }
    int VGetField(unsigned int tag, va_list ap) {
        return TIFFVGetField(tif, tag, ap);
    }
    int GetFieldDefaulted(unsigned int tag) {
        return TIFFGetFieldDefaulted(tif, tag);
    }
    int VGetFieldDefaulted(unsigned int tag, va_list ap) {
        return TIFFVGetFieldDefaulted(tif, tag, ap);
    }
    int ReadDirectory() {
        return TIFFReadDirectory(tif);
    }
    int ReadCustomDirectory(uint64_t diroff, const TIFFFieldArray * infoarray) {
        return TIFFReadCustomDirectory(tif, diroff, infoarray);
    }
    int ReadEXIFDirectory(uint64_t diroff) {
        return TIFFReadEXIFDirectory(tif, diroff);
    }
    uint64 ScanlineSize64() {
        return TIFFScanlineSize64(tif);
    }
    tmsize_t ScanlineSize() {
        return TIFFScanlineSize(tif);
    }
    uint64 RasterScanlineSize64() {
        return TIFFRasterScanlineSize64(tif);
    }
    tmsize_t RasterScanlineSize() {
        return TIFFRasterScanlineSize(tif);
    }
    uint64 StripSize64() {
        return TIFFStripSize64(tif);
    }
    tmsize_t StripSize() {
        return TIFFStripSize(tif);
    }
    uint64 RawStripSize64(unsigned int strip) {
        return TIFFRawStripSize64(tif, strip);
    }
    tmsize_t RawStripSize(unsigned int strip) {
        return TIFFRawStripSize(tif, strip);
    }
    uint64 VStripSize64(unsigned int nrows) {
        return TIFFVStripSize64(tif, nrows);
    }
    tmsize_t VStripSize(unsigned int nrows) {
        return TIFFVStripSize(tif, nrows);
    }
    uint64 TileRowSize64() {
        return TIFFTileRowSize64(tif);
    }
    tmsize_t TileRowSize() {
        return TIFFTileRowSize(tif);
    }
    uint64 TileSize64() {
        return TIFFTileSize64(tif);
    }
    tmsize_t TileSize() {
        return TIFFTileSize(tif);
    }
    uint64 VTileSize64(unsigned int nrows) {
        return TIFFVTileSize64(tif, nrows);
    }
    tmsize_t VTileSize(unsigned int nrows) {
        return TIFFVTileSize(tif, nrows);
    }
    uint32 DefaultStripSize(unsigned int request) {
        return TIFFDefaultStripSize(tif, request);
    }
    void DefaultTileSize(unsigned int p0, unsigned int p1) {
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
    uint32 CurrentRow() {
        return TIFFCurrentRow(tif);
    }
    uint16 CurrentDirectory() {
        return TIFFCurrentDirectory(tif);
    }
    uint16 NumberOfDirectories() {
        return TIFFNumberOfDirectories(tif);
    }
    uint64 CurrentDirOffset() {
        return TIFFCurrentDirOffset(tif);
    }
    uint32 CurrentStrip() {
        return TIFFCurrentStrip(tif);
    }
    uint32 CurrentTile() {
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
    int LastDirectory() {
        return TIFFLastDirectory(tif);
    }
    int SetDirectory(unsigned short int p0) {
        return TIFFSetDirectory(tif, p0);
    }
    int SetSubDirectory(uint64_t p0) {
        return TIFFSetSubDirectory(tif, p0);
    }
    int UnlinkDirectory(unsigned short int p0) {
        return TIFFUnlinkDirectory(tif, p0);
    }
    int SetField(unsigned int p0) {
        return TIFFSetField(tif, p0);
    }
    int VSetField(unsigned int p0, va_list ) {
        return TIFFVSetField(tif, p0);
    }
    int UnsetField(unsigned int p0) {
        return TIFFUnsetField(tif, p0);
    }
    int WriteDirectory() {
        return TIFFWriteDirectory(tif);
    }
    int WriteCustomDirectory(uint64_t p0) {
        return TIFFWriteCustomDirectory(tif, p0);
    }
    int CheckpointDirectory() {
        return TIFFCheckpointDirectory(tif);
    }
    int RewriteDirectory() {
        return TIFFRewriteDirectory(tif);
    }
    void PrintDirectory(FILE * p0, long p1) {
        TIFFPrintDirectory(tif, p0, p1);
    }
    int ReadScanline(void * buf, unsigned int row, unsigned short int sample) {
        return TIFFReadScanline(tif, buf, row, sample);
    }
    int WriteScanline(void * buf, unsigned int row, unsigned short int sample) {
        return TIFFWriteScanline(tif, buf, row, sample);
    }
    int ReadRGBAImage(unsigned int p0, unsigned int p1, unsigned int p2, int p3) {
        return TIFFReadRGBAImage(tif, p0, p1, p2, p3);
    }
    int ReadRGBAImageOriented(unsigned int p0, unsigned int p1, unsigned int p2, int p3, int p4) {
        return TIFFReadRGBAImageOriented(tif, p0, p1, p2, p3, p4);
    }
    void PrintDirectory(FILE * p0, long p1) {
        TIFFPrintDirectory(tif, p0, p1);
    }
    int ReadScanline(void * buf, unsigned int row, unsigned short int sample) {
        return TIFFReadScanline(tif, buf, row, sample);
    }
    int WriteScanline(void * buf, unsigned int row, unsigned short int sample) {
        return TIFFWriteScanline(tif, buf, row, sample);
    }
    int ReadRGBAImage(unsigned int p0, unsigned int p1, unsigned int p2, int p3) {
        return TIFFReadRGBAImage(tif, p0, p1, p2, p3);
    }
    int ReadRGBAImageOriented(unsigned int p0, unsigned int p1, unsigned int p2, int p3, int p4) {
        return TIFFReadRGBAImageOriented(tif, p0, p1, p2, p3, p4);
    }
    int ReadRGBAStrip(unsigned int p0, unsigned int p1) {
        return TIFFReadRGBAStrip(tif, p0, p1);
    }
    int ReadRGBATile(unsigned int p0, unsigned int p1, unsigned int p2) {
        return TIFFReadRGBATile(tif, p0, p1, p2);
    }
    int ReadRGBAStripExt(unsigned int p0, unsigned int p1, int stop_on_error) {
        return TIFFReadRGBAStripExt(tif, p0, p1, stop_on_error);
    }
    int ReadRGBATileExt(unsigned int p0, unsigned int p1, unsigned int p2, int stop_on_error) {
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
    uint32 ComputeTile(unsigned int x, unsigned int y, unsigned int z, unsigned short int s) {
        return TIFFComputeTile(tif, x, y, z, s);
    }
    int CheckTile(unsigned int x, unsigned int y, unsigned int z, unsigned short int s) {
        return TIFFCheckTile(tif, x, y, z, s);
    }
    uint32 NumberOfTiles() {
        return TIFFNumberOfTiles(tif);
    }
    tmsize_t ReadTile(void * buf, unsigned int x, unsigned int y, unsigned int z, unsigned short int s) {
        return TIFFReadTile(tif, buf, x, y, z, s);
    }
    tmsize_t WriteTile(void * buf, unsigned int x, unsigned int y, unsigned int z, unsigned short int s) {
        return TIFFWriteTile(tif, buf, x, y, z, s);
    }
    uint32 ComputeStrip(unsigned int p0, unsigned short int p1) {
        return TIFFComputeStrip(tif, p0, p1);
    }
    uint32 NumberOfStrips() {
        return TIFFNumberOfStrips(tif);
    }
    tmsize_t ReadEncodedStrip(unsigned int strip, void * buf, tmsize_t size) {
        return TIFFReadEncodedStrip(tif, strip, buf, size);
    }
    tmsize_t ReadRawStrip(unsigned int strip, void * buf, tmsize_t size) {
        return TIFFReadRawStrip(tif, strip, buf, size);
    }
    tmsize_t ReadEncodedTile(unsigned int tile, void * buf, tmsize_t size) {
        return TIFFReadEncodedTile(tif, tile, buf, size);
    }
    tmsize_t ReadRawTile(unsigned int tile, void * buf, tmsize_t size) {
        return TIFFReadRawTile(tif, tile, buf, size);
    }
    tmsize_t WriteEncodedStrip(unsigned int strip, void * data, tmsize_t cc) {
        return TIFFWriteEncodedStrip(tif, strip, data, cc);
    }
    tmsize_t WriteRawStrip(unsigned int strip, void * data, tmsize_t cc) {
        return TIFFWriteRawStrip(tif, strip, data, cc);
    }
    tmsize_t WriteEncodedTile(unsigned int tile, void * data, tmsize_t cc) {
        return TIFFWriteEncodedTile(tif, tile, data, cc);
    }
    tmsize_t WriteRawTile(unsigned int tile, void * data, tmsize_t cc) {
        return TIFFWriteRawTile(tif, tile, data, cc);
    }
    void SetWriteOffset(uint64_t off) {
        TIFFSetWriteOffset(tif, off);
    }
    int MergeFieldInfo(const TIFFFieldInfo[], unsigned int p1) {
        return TIFFMergeFieldInfo(tif, TIFFFieldInfo, p1);
    }
};

#endif /* __TIFF_OBJ__H__ */
