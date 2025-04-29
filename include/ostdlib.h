/* ostdlib.h
*/
#ifndef _OSTDLIB_H
#define _OSTDLIB_H

#ifdef __cplusplus
extern "C"
{
#endif				/* __cplusplus */

#include <stdlib.h>

#ifndef oDeprecated
#if defined(__GNUC__) || defined(__clang__)
#define oDeprecated(new, old) \
 __typeof__(old) old __attribute__((deprecated("Use " #new " instead")))
#else
#define oDeprecated(new, old)
#endif
#endif

#ifndef oDeprecatedDisable
#if defined(__GNUC__) || defined(__clang__)
#define oDeprecatedDisable() \
 _Pragma("GCC diagnostic push") \
 _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#else
#define oDeprecatedDisable()
#endif
#endif

#ifndef oDeprecatedEnable
#if defined(__GNUC__) || defined(__clang__)
#define oDeprecatedEnable() \
 _Pragma("GCC diagnostic pop")
#else
#define oDeprecatedEnable()
#endif
#endif

  oDeprecatedDisable ();

#ifndef oPvoid
  typedef struct oPvoid
  {
    char (*isPresent) (struct oPvoid self);
    void *get;
    size_t size;
    unsigned char *isAllocated;
    char isAllocatedOffset;
    char freeAble;
    char (*free) (struct oPvoid self);
    unsigned long long moved[8];
  } oPvoid;
#define oPvoid oPvoid
#endif

#ifndef oPchar
  typedef struct oPchar
  {
    char (*isPresent) (struct oPchar self);
    char *get;
    size_t size;
    unsigned char *isAllocated;
    char isAllocatedOffset;
    char freeAble;
    char (*free) (struct oPchar self);
    unsigned long long moved[8];
  } oPchar;
#define oPchar oPchar
#endif

#ifndef oPsize_t
  typedef struct oPsize_t
  {
    char (*isPresent) (struct oPsize_t self);
    size_t *get;
    size_t size;
    unsigned char *isAllocated;
    char isAllocatedOffset;
    char freeAble;
    char (*free) (struct oPsize_t self);
    unsigned long long moved[8];
  } oPsize_t;
#define oPsize_t oPsize_t
#endif

#ifndef uoPvoidConvertable
  typedef union
  {
    oPvoid soPvoid;
    oPchar soPchar;
    oPsize_t soPsize_t;
  } uoPvoidConvertable;
#define UoPvoidConvertable UoPvoidConvertable
#endif

#ifndef oPvoidConvertoPchar
  static oPchar oPvoidConvertoPchar (oPvoid from)
  {
    uoPvoidConvertable u;
      u.soPvoid = from;
      return u.soPchar;
  }
#define oPvoidConvertoPchar oPvoidConvertoPchar
#endif

#ifndef oPvoidConvertoPsize_t
  static oPsize_t oPvoidConvertoPsize_t (oPvoid from)
  {
    uoPvoidConvertable u;
    u.soPvoid = from;
    return u.soPsize_t;
  }
#define oPvoidConvertoPsize_t oPvoidConvertoPsize_t
#endif

#ifndef oPcharConvertoPvoid
  static oPvoid oPcharConvertoPvoid (oPchar from)
  {
    uoPvoidConvertable u;
    u.soPchar = from;
    return u.soPvoid;
  }
#define oPcharConvertoPvoid oPcharConvertoPvoid
#endif

#ifndef oPsize_tConvertoPvoid
  static oPvoid oPsize_tConvertoPvoid (oPsize_t from)
  {
    uoPvoidConvertable u;
    u.soPsize_t = from;
    return u.soPvoid;
  }
#define oPsize_tConvertoPvoid oPsize_tConvertoPvoid
#endif

#ifndef _OSTDLIB_HAllocRecord
  typedef struct
  {
    void *ptr;
    size_t size;
    unsigned char *isAllocated;
    char isAllocatedOffset;
  } _OSTDLIB_HAllocRecord;
#define _OSTDLIB_HAllocRecord _OSTDLIB_HAllocRecord
#endif

#ifndef _OSTDLIB_HAllocationBitmap
  static unsigned char *_OSTDLIB_HAllocationBitmap[64] = { 0 };
#define _OSTDLIB_HAllocationBitmap _OSTDLIB_HAllocationBitmap
#endif
#ifndef _OSTDLIB_HAllocationBitmapPos
  static size_t _OSTDLIB_HAllocationBitmapPos = 0;
#define _OSTDLIB_HAllocationBitmapPos _OSTDLIB_HAllocationBitmapPos
#endif
#ifndef _OSTDLIB_HBytePos
  static size_t _OSTDLIB_HBytePos = 0;
#define _OSTDLIB_HBytePos _OSTDLIB_HBytePos
#endif
#ifndef _OSTDLIB_HBitPos
  static size_t _OSTDLIB_HBitPos = 0;
#define _OSTDLIB_HBitPos _OSTDLIB_HBitPos
#endif
#ifndef _OSTDLIB_HNAllocation
  static size_t _OSTDLIB_HNAllocation = 0;
#define _OSTDLIB_HNAllocation _OSTDLIB_HNAllocation
#endif
#ifndef _OSTDLIB_HMoved
  static unsigned long long _OSTDLIB_HMoved[8] = { 0 };
#define _OSTDLIB_HMoved _OSTDLIB_HMoved
#endif
#ifndef _OSTDLIB_HAllocRecords
  static _OSTDLIB_HAllocRecord *_OSTDLIB_HAllocRecords = NULL;
#define _OSTDLIB_HAllocRecords _OSTDLIB_HAllocRecords
#endif
#ifndef _OSTDLIB_HAllocRecordsCount
  static size_t _OSTDLIB_HAllocRecordsCount = 0;
#define _OSTDLIB_HAllocRecordsCount _OSTDLIB_HAllocRecordsCount
#endif
#ifndef _OSTDLIB_HAllocRecordsCapacity
  static size_t _OSTDLIB_HAllocRecordsCapacity = 0;
#define _OSTDLIB_HAllocRecordsCapacity _OSTDLIB_HAllocRecordsCapacity
#endif
#ifndef _OSTDLIB_HHasOverflowed
  static char _OSTDLIB_HHasOverflowed = 0;
#define _OSTDLIB_HHasOverflowed _OSTDLIB_HHasOverflowed
#endif

#ifndef _OSTDLIB_HUFPCharBABBoPvoidBFPCharBABBB
  typedef union
  {
    char (*p1) (struct oPvoid self);
    char (*p2) ();
  } _OSTDLIB_HUFPCharBABBoPvoidBFPCharBABBB;
#define _OSTDLIB_HUFPCharBABBoPvoidBFPCharBABBB _OSTDLIB_HUFPCharBABBoPvoidBFPCharBABBB
#endif

#ifndef _OSTDLIB_HoNotPresent
  static char _OSTDLIB_HoNotPresent ()
  {
    return 0;
  }
#define _OSTDLIB_HoNotPresent _OSTDLIB_HoNotPresent
#endif

#ifndef _OSTDLIB_HoPvoidIsPresent
  static char _OSTDLIB_HoPvoidIsPresent (struct oPvoid self)
  {
    size_t i;
    for (i = 0; i != sizeof (self.moved) / sizeof (*self.moved); i++)
      {
	if (self.moved[i] != _OSTDLIB_HMoved[i])
	  return 0;
      }
    if (_OSTDLIB_HHasOverflowed)
      {
	for (i = 0; i != _OSTDLIB_HAllocRecordsCount; i++)
	  {
	    if (_OSTDLIB_HAllocRecords[i].ptr == self.get
		&& _OSTDLIB_HAllocRecords[i].size == self.size
		&& _OSTDLIB_HAllocRecords[i].isAllocated == self.isAllocated
		&& _OSTDLIB_HAllocRecords[i].isAllocatedOffset ==
		self.isAllocatedOffset)
	      {
		return 1;
	      }
	  }
	return 0;
      }
    return (*self.isAllocated >> self.isAllocatedOffset) & 1;
  }
#define _OSTDLIB_HoPvoidIsPresent _OSTDLIB_HoPvoidIsPresent
#endif

#ifndef _OSTDLIB_HoFreeMalloc
  static char _OSTDLIB_HoFreeMalloc (oPvoid self)
  {
    size_t i;
    if (!self.freeAble)
      return 0;
    if (_OSTDLIB_HHasOverflowed)
      {
	for (i = 0; i != _OSTDLIB_HAllocRecordsCount; i++)
	  {
	    if (_OSTDLIB_HAllocRecords[i].ptr == self.get
		&& _OSTDLIB_HAllocRecords[i].size == self.size
		&& _OSTDLIB_HAllocRecords[i].isAllocated == self.isAllocated
		&& _OSTDLIB_HAllocRecords[i].isAllocatedOffset ==
		self.isAllocatedOffset)
	      {
		_OSTDLIB_HAllocRecordsCount--;
		for (; i != _OSTDLIB_HAllocRecordsCount; i++)
		  {
		    _OSTDLIB_HAllocRecords[i] = _OSTDLIB_HAllocRecords[i + 1];
		  }
		i--;
	      }
	  }
      }
    *self.isAllocated &= ~(1 << self.isAllocatedOffset);
    _OSTDLIB_HNAllocation--;
    if (!_OSTDLIB_HNAllocation)
      {
	for (i = 0; i != sizeof (_OSTDLIB_HMoved) / sizeof (*_OSTDLIB_HMoved);
	     i++)
	  {
	    _OSTDLIB_HMoved[i]++;
	    if (_OSTDLIB_HMoved[i])
	      {
		break;
	      }
	  }
	_OSTDLIB_HHasOverflowed |= !_OSTDLIB_HMoved[i];
	if (_OSTDLIB_HHasOverflowed)
	  {
	    if (_OSTDLIB_HAllocRecords)
	      {
		free (_OSTDLIB_HAllocRecords);
	      }
	    _OSTDLIB_HAllocRecords = NULL;
	    _OSTDLIB_HAllocRecordsCount = 0;
	    _OSTDLIB_HAllocRecordsCapacity = 0;
	  }
	for (i = 0;
	     i !=
	     sizeof (_OSTDLIB_HAllocationBitmap) /
	     sizeof (*_OSTDLIB_HAllocationBitmap); i++)
	  {
	    if (_OSTDLIB_HAllocationBitmap[i])
	      {
		free (_OSTDLIB_HAllocationBitmap[i]);
	      }
	    _OSTDLIB_HAllocationBitmap[i] = NULL;
	  }
	_OSTDLIB_HAllocationBitmapPos = 0;
	_OSTDLIB_HBytePos = 0;
	_OSTDLIB_HBitPos = 0;
      }
    return 1;
  }
#define _OSTDLIB_HoFreeMalloc _OSTDLIB_HoFreeMalloc
#endif

  oDeprecated (omalloc, malloc);
  static oPvoid omalloc (size_t size)
  {
    oPvoid p = { 0 };
    size_t newCap;
    _OSTDLIB_HAllocRecord *newRecs;
    size_t i;
    const size_t currentBitmapSize = 1 << _OSTDLIB_HAllocationBitmapPos;
    _OSTDLIB_HUFPCharBABBoPvoidBFPCharBABBB u;
    u.p2 = _OSTDLIB_HoNotPresent;
    p.isPresent = u.p1;
    if (!_OSTDLIB_HAllocationBitmap[_OSTDLIB_HAllocationBitmapPos])
      {
	_OSTDLIB_HAllocationBitmap[_OSTDLIB_HAllocationBitmapPos] =
	  malloc (currentBitmapSize);
	if (!_OSTDLIB_HAllocationBitmap[_OSTDLIB_HAllocationBitmapPos])
	  return p;
      }
    if (_OSTDLIB_HHasOverflowed
	&& _OSTDLIB_HAllocRecordsCount == _OSTDLIB_HAllocRecordsCapacity)
      {
	newCap =
	  _OSTDLIB_HAllocRecordsCapacity ? _OSTDLIB_HAllocRecordsCapacity *
	  2 : 16;
	if (_OSTDLIB_HAllocRecordsCapacity)
	  {
	    newRecs =
	      realloc (_OSTDLIB_HAllocRecords,
		       newCap * sizeof (*_OSTDLIB_HAllocRecords));
	  }
	else
	  {
	    newRecs = malloc (newCap * sizeof (*_OSTDLIB_HAllocRecords));
	  }
	if (!newRecs)
	  {
	    _OSTDLIB_HAllocationBitmap[_OSTDLIB_HAllocationBitmapPos]
	      [_OSTDLIB_HBytePos] &= ~(1 << _OSTDLIB_HBitPos);
	    return p;
	  }
	_OSTDLIB_HAllocRecords = newRecs;
	_OSTDLIB_HAllocRecordsCapacity = newCap;
      }
    _OSTDLIB_HAllocationBitmap[_OSTDLIB_HAllocationBitmapPos]
      [_OSTDLIB_HBytePos] |= (1 << _OSTDLIB_HBitPos);
    p.get = malloc (size);
    if (!p.get)
      {
	_OSTDLIB_HAllocationBitmap[_OSTDLIB_HAllocationBitmapPos]
	  [_OSTDLIB_HBytePos] &= ~(1 << _OSTDLIB_HBitPos);
	return p;
      }
    p.size = size;
    p.isAllocated =
      _OSTDLIB_HAllocationBitmap[_OSTDLIB_HAllocationBitmapPos] +
      _OSTDLIB_HBytePos;
    p.isAllocatedOffset = _OSTDLIB_HBitPos;
    p.freeAble = 1;
    p.free = _OSTDLIB_HoFreeMalloc;
    p.isPresent = _OSTDLIB_HoPvoidIsPresent;
    for (i = 0; i != sizeof (p.moved) / sizeof (*p.moved); i++)
      {
	p.moved[i] = _OSTDLIB_HMoved[i];
      }
    if (_OSTDLIB_HHasOverflowed)
      {
	_OSTDLIB_HAllocRecords[_OSTDLIB_HAllocRecordsCount] =
	  (_OSTDLIB_HAllocRecord)
	{
	p.get, p.size, p.isAllocated, p.isAllocatedOffset};
	_OSTDLIB_HAllocRecordsCount++;
      }
    _OSTDLIB_HNAllocation++;
    _OSTDLIB_HBitPos++;
    if (_OSTDLIB_HBitPos == sizeof (**_OSTDLIB_HAllocationBitmap) << 3)
      {
	_OSTDLIB_HBitPos = 0;
	_OSTDLIB_HBytePos++;
	if (_OSTDLIB_HBytePos == currentBitmapSize)
	  {
	    _OSTDLIB_HAllocationBitmapPos++;
	    _OSTDLIB_HBytePos = 0;
	  }
      }
    return p;
  }

  oDeprecated (ofree, free);
  void ofree (oPvoid data)
  {
    if (data.freeAble && data.isPresent (data))
      data.free (data);
  }

  oDeprecatedEnable ();
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ostdlib.h */
