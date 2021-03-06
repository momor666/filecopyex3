/*
FileCopyEx - Extended File Copy plugin for Far 2 file manager

Copyright (C) 2004 - 2010
Idea & core: Max Antipin
Coding: Serge Cheperis aka craZZy
Bugfixes: slst, CDK, Ivanych, Alter, Axxie and Nsky
Special thanks to Vitaliy Tsubin
Far 2 (32 & 64 bit) full unicode version by djdron

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "StdHdr.h"
#include "ObjString.h"

const int MAX_FILENAME = 4096;
const int DEFAULT_SECTOR_SIZE = 4096;

const int OPEN_BUF = 128;
const int OPEN_READ = 1;
const int OPEN_CREATE = 2;
const int OPEN_APPEND = 4;
const int OPEN_WRITE = 8;
const int OPEN_WRITE_BUF = OPEN_WRITE | OPEN_BUF;

#define LO32(i) (int)(i & 0xFFFFFFFF)
#define HI32(i) (int)(i >> 32)

String GetLongFileName(const String & FileName);
String GetShortFileName(const String & FileName);
String ExtractFileName(const String &);
String ExtractFilePath(const String &);
String ExtractFileExt(const String &);
String CutEndSlash(const String &);
String AddEndSlash(const String &);
String ChangeFileExt(const String &, const String &);

const int gslExpandSubst = 1;
const int gslExpandNetMappings = 2;
const int gslExpandReparsePoints = 4;
const int gslExpandMountPoints = 8;

const int rfnNoNetExpand = 1;

extern HANDLE FOpen(const String & fn, DWORD mode, DWORD attr);
void FClose(HANDLE & h);
bool FDelete(const String & fn);

String GetFileRoot(const String &);
String GetRealFileName(const String &, uint32_t flags = 0);
bool GetSymLink(const String & dir, String & res, uint32_t flags);
String GetFileNameRoot(const String &);
String ExpandEnv(const String &);

String ApplyFileMask(const String & name, const String & mask);
String ApplyFileMaskPath(const String & name, const String & mask);

bool FileExists(const String & name);
bool FMoveFile(const String & src, const String & dst, bool Replace);
void ForceDirectories(const String & s);

int64_t FileSize(HANDLE h);
int64_t FileSize(const String & fn);

String TempName();
String TempPath();
String TempPathName();

void Out(const String & s);

bool GetPrimaryVolumeMountPoint(const String & VolumeMountPointForPath, String & PrimaryVolumeMountPoint);

