#include "aobscan.h"

int main(int argc, char* argv)
{
	std::vector <DWORD> vResultContainer = AobScan::FindSigX32(6580, "E86D86??FF", 0, 0x7fffffff);
	int nSize1 = 0;
	for (auto it = vResultContainer.begin(); it != vResultContainer.end();it++)
	{
		wchar_t buf[64] = { 0 };
		wsprintf(buf, L"%03d 0x%08X\n", nSize1, *it);
		OutputDebugString(buf);
		nSize1++;
	}

	std::vector <ULONG64> dwRet = AobScan::FindSigX64("697469??6C697A65", 5648,0x77111000, -1);
	int nSize2 = 0;
	for (auto it = dwRet.begin(); it != dwRet.end(); it++)
	{
		wchar_t buf[64] = { 0 };
		wsprintf(buf, L"%03d 0x%016I64X\n", nSize2, *it);
		OutputDebugString(buf);
		nSize2++;
	}
	return 0;
}