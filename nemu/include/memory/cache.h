#ifndef __CACHE_H__
#define __CACHE_H__

#include "common.h"

typedef struct CacheBlock{
	bool valid;
	uint32_t tag;		
	uint8_t data[64];
}CacheBlock;

#define CacheSize (64 << 10)
#define CacheBlockSize 64

#define CacheRow (CacheSize/CacheBlockSize)

CacheBlock cache[CacheRow];

#define ROWNUM 8
#define GROUPNUM (CacheRow/ROWNUM)

#define TAG(addr) ((addr >> 13) & 0x7ffff)
#define INDEX(addr) ((addr >> 6) & 0x7f)
#define ADDR(addr) (addr & 0x3f)

#define GPADDR(addr) (cache + ROWNUM * INDEX(addr)) 

void init_cache();

bool shot(hwaddr_t , CacheBlock* );

void CacheWriteByte(hwaddr_t , uint8_t );
void CacheReadByte(hwaddr_t, uint8_t *);

//size_t CacheWrite(hwaddr_t, CacheBlock *, size_t , uint32_t );
//size_t CacheRead(hwaddr_t, CacheBlock *, size_t , uint32_t* );

#endif
