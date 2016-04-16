//.---------------------------------------------------------------------------------------------
//.
//.z827.c
//.Created by Daniel Dusabimana on 2/24/16.
//.Copyright(c) 2016 danieldusabimana. All rights reserved.
//.
//.---------------------------------------------------------------------------------------------
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
//.
//.
#define     BUFF_SZ		(8)               //.64-bit or 8-Byte Block Size
#define     FILE_BUFF_SZ	(8 * 1024 * 1024) //.8 MB Buffer for File I/O
//.
//.
typedef struct { //.Structure for Block with 64 bit-fields or 8 Bytes
	unsigned int _00_64 : 1;
	unsigned int _01_64 : 1;
	unsigned int _02_64 : 1;
	unsigned int _03_64 : 1;
	unsigned int _04_64 : 1;
	unsigned int _05_64 : 1;
	unsigned int _06_64 : 1;
	unsigned int _07_64 : 1;
	unsigned int _08_64 : 1;
	unsigned int _09_64 : 1;
	unsigned int _10_64 : 1;
	unsigned int _11_64 : 1;
	unsigned int _12_64 : 1;
	unsigned int _13_64 : 1;
	unsigned int _14_64 : 1;
	unsigned int _15_64 : 1;
	unsigned int _16_64 : 1;
	unsigned int _17_64 : 1;
	unsigned int _18_64 : 1;
	unsigned int _19_64 : 1;
	unsigned int _20_64 : 1;
	unsigned int _21_64 : 1;
	unsigned int _22_64 : 1;
	unsigned int _23_64 : 1;
	unsigned int _24_64 : 1;
	unsigned int _25_64 : 1;
	unsigned int _26_64 : 1;
	unsigned int _27_64 : 1;
	unsigned int _28_64 : 1;
	unsigned int _29_64 : 1;
	unsigned int _30_64 : 1;
	unsigned int _31_64 : 1;
	unsigned int _32_64 : 1;
	unsigned int _33_64 : 1;
	unsigned int _34_64 : 1;
	unsigned int _35_64 : 1;
	unsigned int _36_64 : 1;
	unsigned int _37_64 : 1;
	unsigned int _38_64 : 1;
	unsigned int _39_64 : 1;
	unsigned int _40_64 : 1;
	unsigned int _41_64 : 1;
	unsigned int _42_64 : 1;
	unsigned int _43_64 : 1;
	unsigned int _44_64 : 1;
	unsigned int _45_64 : 1;
	unsigned int _46_64 : 1;
	unsigned int _47_64 : 1;
	unsigned int _48_64 : 1;
	unsigned int _49_64 : 1;
	unsigned int _50_64 : 1;
	unsigned int _51_64 : 1;
	unsigned int _52_64 : 1;
	unsigned int _53_64 : 1;
	unsigned int _54_64 : 1;
	unsigned int _55_64 : 1;
	unsigned int _56_64 : 1;
	unsigned int _57_64 : 1;
	unsigned int _58_64 : 1;
	unsigned int _59_64 : 1;
	unsigned int _60_64 : 1;
	unsigned int _61_64 : 1;
	unsigned int _62_64 : 1;
	unsigned int _63_64 : 1;
} _64bits;
//.
//.---------------------------------------------------------------------------------------------
//.
//.GetTimeInMillis Function - Utility function to get current time in milliseconds
//.Using gettimeofday even though it's been markes as obsolete
//.clock_gettime not in OSX yet, hence using the deprecated POSIX function gettimeofday
//.
long long gettimeinmillis()
{
	long long llMilliX;
	struct timeval sttmvX;
	//.
	gettimeofday(&sttmvX, NULL); //.clock_gettime not yet in OSX POSIX implementation
	llMilliX = (sttmvX.tv_sec * (long long)1000) + (sttmvX.tv_usec / (long long)1000);
	//.
	return(llMilliX);
}
//.
//.---------------------------------------------------------------------------------------------
//.
//.Decompression Function - Copies bits from Src To Dst adding MSB
//.
int decompress(char * buffIn, char * buffOut)
{
	//.
	_64bits * p64X;
	_64bits * p64Y;
	long long * llpIn;
	long long * llpOut;
	//.
	llpIn = (long long *)buffIn;
	llpOut = (long long *)buffOut;
	p64X = (_64bits *)llpIn;
	p64Y = (_64bits *)llpOut;
	//.
	p64Y->_00_64 = p64X->_00_64;
	p64Y->_01_64 = p64X->_01_64;
	p64Y->_02_64 = p64X->_02_64;
	p64Y->_03_64 = p64X->_03_64;
	p64Y->_04_64 = p64X->_04_64;
	p64Y->_05_64 = p64X->_05_64;
	p64Y->_06_64 = p64X->_06_64;
	p64Y->_07_64 = 0;
	//.
	p64Y->_08_64 = p64X->_07_64;
	p64Y->_09_64 = p64X->_08_64;
	p64Y->_10_64 = p64X->_09_64;
	p64Y->_11_64 = p64X->_10_64;
	p64Y->_12_64 = p64X->_11_64;
	p64Y->_13_64 = p64X->_12_64;
	p64Y->_14_64 = p64X->_13_64;
	p64Y->_15_64 = 0;
	//.
	p64Y->_16_64 = p64X->_14_64;
	p64Y->_17_64 = p64X->_15_64;
	p64Y->_18_64 = p64X->_16_64;
	p64Y->_19_64 = p64X->_17_64;
	p64Y->_20_64 = p64X->_18_64;
	p64Y->_21_64 = p64X->_19_64;
	p64Y->_22_64 = p64X->_20_64;
	p64Y->_23_64 = 0;
	//.
	p64Y->_24_64 = p64X->_21_64;
	p64Y->_25_64 = p64X->_22_64;
	p64Y->_26_64 = p64X->_23_64;
	p64Y->_27_64 = p64X->_24_64;
	p64Y->_28_64 = p64X->_25_64;
	p64Y->_29_64 = p64X->_26_64;
	p64Y->_30_64 = p64X->_27_64;
	p64Y->_31_64 = 0;
	//.
	p64Y->_32_64 = p64X->_28_64;
	p64Y->_33_64 = p64X->_29_64;
	p64Y->_34_64 = p64X->_30_64;
	p64Y->_35_64 = p64X->_31_64;
	p64Y->_36_64 = p64X->_32_64;
	p64Y->_37_64 = p64X->_33_64;
	p64Y->_38_64 = p64X->_34_64;
	p64Y->_39_64 = 0;
	//.
	p64Y->_40_64 = p64X->_35_64;
	p64Y->_41_64 = p64X->_36_64;
	p64Y->_42_64 = p64X->_37_64;
	p64Y->_43_64 = p64X->_38_64;
	p64Y->_44_64 = p64X->_39_64;
	p64Y->_45_64 = p64X->_40_64;
	p64Y->_46_64 = p64X->_41_64;
	p64Y->_47_64 = 0;
	//.
	p64Y->_48_64 = p64X->_42_64;
	p64Y->_49_64 = p64X->_43_64;
	p64Y->_50_64 = p64X->_44_64;
	p64Y->_51_64 = p64X->_45_64;
	p64Y->_52_64 = p64X->_46_64;
	p64Y->_53_64 = p64X->_47_64;
	p64Y->_54_64 = p64X->_48_64;
	p64Y->_55_64 = 0;
	//.
	p64Y->_56_64 = p64X->_49_64;
	p64Y->_57_64 = p64X->_50_64;
	p64Y->_58_64 = p64X->_51_64;
	p64Y->_59_64 = p64X->_52_64;
	p64Y->_60_64 = p64X->_53_64;
	p64Y->_61_64 = p64X->_54_64;
	p64Y->_62_64 = p64X->_55_64;
	p64Y->_63_64 = 0;
	//.
	return(0);
}
//.
//.---------------------------------------------------------------------------------------------
//.
//.Compression Function - Copies bits from Src To Dst skipping MSB
//.
int compress(char * buffIn, char * buffOut)
{
	//.
	_64bits * p64X;
	_64bits * p64Y;
	long long * llpIn;
	long long * llpOut;
	//.
	llpIn = (long long *)buffIn;
	llpOut = (long long *)buffOut;
	p64X = (_64bits *)llpIn;
	p64Y = (_64bits *)llpOut;
	//.
	p64Y->_00_64 = p64X->_00_64;
	p64Y->_01_64 = p64X->_01_64;
	p64Y->_02_64 = p64X->_02_64;
	p64Y->_03_64 = p64X->_03_64;
	p64Y->_04_64 = p64X->_04_64;
	p64Y->_05_64 = p64X->_05_64;
	p64Y->_06_64 = p64X->_06_64;
	//.
	p64Y->_07_64 = p64X->_08_64;
	p64Y->_08_64 = p64X->_09_64;
	p64Y->_09_64 = p64X->_10_64;
	p64Y->_10_64 = p64X->_11_64;
	p64Y->_11_64 = p64X->_12_64;
	p64Y->_12_64 = p64X->_13_64;
	p64Y->_13_64 = p64X->_14_64;
	//.
	p64Y->_14_64 = p64X->_16_64;
	p64Y->_15_64 = p64X->_17_64;
	p64Y->_16_64 = p64X->_18_64;
	p64Y->_17_64 = p64X->_19_64;
	p64Y->_18_64 = p64X->_20_64;
	p64Y->_19_64 = p64X->_21_64;
	p64Y->_20_64 = p64X->_22_64;
	//.
	p64Y->_21_64 = p64X->_24_64;
	p64Y->_22_64 = p64X->_25_64;
	p64Y->_23_64 = p64X->_26_64;
	p64Y->_24_64 = p64X->_27_64;
	p64Y->_25_64 = p64X->_28_64;
	p64Y->_26_64 = p64X->_29_64;
	p64Y->_27_64 = p64X->_30_64;
	//.
	p64Y->_28_64 = p64X->_32_64;
	p64Y->_29_64 = p64X->_33_64;
	p64Y->_30_64 = p64X->_34_64;
	p64Y->_31_64 = p64X->_35_64;
	p64Y->_32_64 = p64X->_36_64;
	p64Y->_33_64 = p64X->_37_64;
	p64Y->_34_64 = p64X->_38_64;
	//.
	p64Y->_35_64 = p64X->_40_64;
	p64Y->_36_64 = p64X->_41_64;
	p64Y->_37_64 = p64X->_42_64;
	p64Y->_38_64 = p64X->_43_64;
	p64Y->_39_64 = p64X->_44_64;
	p64Y->_40_64 = p64X->_45_64;
	p64Y->_41_64 = p64X->_46_64;
	//.
	p64Y->_42_64 = p64X->_48_64;
	p64Y->_43_64 = p64X->_49_64;
	p64Y->_44_64 = p64X->_50_64;
	p64Y->_45_64 = p64X->_51_64;
	p64Y->_46_64 = p64X->_52_64;
	p64Y->_47_64 = p64X->_53_64;
	p64Y->_48_64 = p64X->_54_64;
	//.
	p64Y->_49_64 = p64X->_56_64;
	p64Y->_50_64 = p64X->_57_64;
	p64Y->_51_64 = p64X->_58_64;
	p64Y->_52_64 = p64X->_59_64;
	p64Y->_53_64 = p64X->_60_64;
	p64Y->_54_64 = p64X->_61_64;
	p64Y->_55_64 = p64X->_62_64;
	//.
	return(0);
}
//.
//.---------------------------------------------------------------------------------------------
//.
int main(int argc, char ** argv)
{
	int nExecFlag;
	char strFileDel[1024];
	char strOutFile[1024];
	long long llStart, llEnd;
	FILE * fpInput, * fpOutput;
	char * pStr;
	char * pInBuffPtr, * pOutBuffPtr;
	char * buffInput, * buffOutput;
	char * buffFileIn, * buffFileOut;
	int nX, nY, nSz, nFileDel, nOrgByts, nFileInt, nBytsRd, nBytsWr, n64bBlks;
	//.
	nFileDel = 1; //.Default : Delete Input File after Processing
	if(argc < 2) {
		printf("z827 - no input file specified");
		printf("\nUsage : z827 file_name [-nodelete]\n");
		return(-1);
	}
	else if(argc > 2) {
		if((strcmp(argv[2], "-nodelete")) == 0) {
			nFileDel = 0; //.Do Not Delete Input File after Processing
		}
		else {
			printf("z827 - too many arguements, proceeding anyway");
			printf("\nUsage : z827 file_name [-nodelete]");
		}
	}
	//.
	nExecFlag = 0;
	llStart = llEnd = 0;
	memset(strFileDel, 0x0, sizeof(strFileDel));
	strcpy(strFileDel, argv[1]);
	memset(strOutFile, 0x0, sizeof(strFileDel));
	strcpy(strOutFile, argv[1]);
	nX = (int)strlen(strOutFile);
	if(nX > 5) {
		nX -= 5;
		pStr = argv[1];
		pStr += nX;
		if((strcmp(pStr, ".z827")) == 0) {
			nExecFlag = 1;
		}
	}
	//.
	fpInput = NULL;
	nX = nY = nSz = nOrgByts = nFileInt = nBytsRd = nBytsWr = n64bBlks = 0;
	pStr = pInBuffPtr = pOutBuffPtr = buffInput = buffOutput = buffFileIn = buffFileOut = NULL;
	//.
	if(nExecFlag) {
		printf("\nz827 - input file : %s - mode : decompression", argv[1]);
	}
	else {
		printf("\nz827 - input file : %s - mode : compression", argv[1]);
	}
	if(nFileDel == 0) {
		printf(", nodelete");
	}
	else {
		printf(", delete");
	}
	//.
	if((fpInput = fopen(argv[1], "r")) != NULL) {
		//.
		llStart = gettimeinmillis();
		buffInput = (char *)malloc(BUFF_SZ * sizeof(char));
		buffOutput = (char *)malloc(BUFF_SZ * sizeof(char));
		buffFileIn = (char *)malloc(FILE_BUFF_SZ * sizeof(char));
		buffFileOut = (char *)malloc(FILE_BUFF_SZ * sizeof(char));
		//.
		memset(buffFileIn, 0x00, FILE_BUFF_SZ);
		memset(buffFileOut, 0x00, FILE_BUFF_SZ);
		nOrgByts = (int)fread(buffFileIn, sizeof(char), FILE_BUFF_SZ, fpInput);
		pInBuffPtr = buffFileIn;
		pOutBuffPtr = buffFileOut;
		if(!nExecFlag) { //.Compress -----------------------------------------------------------
			n64bBlks = (int)((nOrgByts / BUFF_SZ) + 1);
			for(nX = 0; nX < n64bBlks; nX++) {
				memset(buffInput, 0x00, BUFF_SZ);
				memset(buffOutput, 0x00, BUFF_SZ);
				memcpy(buffInput, pInBuffPtr, BUFF_SZ); //.Playing it safe & using an intermediate buffer
				compress(buffInput, buffOutput);
				memcpy(pOutBuffPtr, buffOutput, (BUFF_SZ - 1));
				pInBuffPtr += BUFF_SZ;
				pOutBuffPtr += (BUFF_SZ - 1);
				nBytsRd += BUFF_SZ;
				nBytsWr += (BUFF_SZ - 1);
			}
			memset(strOutFile, 0x0, sizeof(strOutFile));
			strcpy(strOutFile, argv[1]);
			strcat(strOutFile, ".z827");
		}
		else { //.DeCompress -------------------------------------------------------------------
			nFileInt = (int)(*((int *)pInBuffPtr));
			pInBuffPtr += sizeof(int);
			n64bBlks = (int)((nFileInt / BUFF_SZ) + 1);
			for(nX = 0; nX < n64bBlks; nX++) {
				memset(buffInput, 0x00, BUFF_SZ);
				memset(buffOutput, 0x00, BUFF_SZ);
				memcpy(buffInput, pInBuffPtr, (BUFF_SZ - 1)); //.Playing it safe & using an intermediate buffer
				decompress(buffInput, buffOutput);
				memcpy(pOutBuffPtr, buffOutput, BUFF_SZ);
				pInBuffPtr += (BUFF_SZ - 1);
				pOutBuffPtr += BUFF_SZ;
				nBytsRd += (BUFF_SZ - 1);
				nBytsWr += BUFF_SZ;
			}
			if(nBytsWr != nFileInt) {
				nBytsWr = nFileInt;
			}
			memset(strOutFile, 0x0, sizeof(strOutFile));
			strcpy(strOutFile, argv[1]);
			nX = (int)strlen(strOutFile);
			if(nX > 5) {
				nX -= 5;
				pStr = strOutFile;
				pStr += nX;
				*pStr = 0x0;
			}
		}
		//.
		if((fpOutput = fopen(strOutFile, "w")) != NULL) {
			if(!nExecFlag) {
				fwrite(&nOrgByts, sizeof(int), 1, fpOutput);
			}
			fwrite(buffFileOut, sizeof(char), nBytsWr, fpOutput);
			fclose(fpOutput);
			//.
			if(nFileDel) {
				if((unlink(strFileDel)) == -1) {
					printf("\nz827 - could not delete input file : %s", strFileDel);
					printf("\nErrNum : %d : [ %s ]\n", errno, strerror(errno));
				}
			}
		}
		else {
			printf("\nz827 - could not open output file : %s", argv[1]);
			printf("\nErrNum : %d : [ %s ]\n", errno, strerror(errno));
		}
		if(fpInput != NULL) {
			fclose(fpInput);
		}
		llEnd = gettimeinmillis();
		printf("\nRead in %d bytes, wrote out %d bytes in %llu milliseconds\n\n", nOrgByts, nBytsWr, (llEnd - llStart));
	}
	else {
		printf("\nz827 - could not open input file : %s", argv[1]);
		printf("\nErrNum : %d : [ %s ]\n\n", errno, strerror(errno));
	}
	//.
	if(buffInput != NULL) {
		free(buffInput);
	}
	if(buffOutput != NULL) {
		free(buffOutput);
	}
	if(buffFileIn != NULL) {
		free(buffFileIn);
	}
	if(buffFileOut != NULL) {
		free(buffFileOut);
	}
	//.
	return(0);
}
//.
//.---------------------------------------------------------------------------------------------
//.
