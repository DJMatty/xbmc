/*
* Copyright (c) 2006 elupus (Joakim Plate)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include "cores/IPlayer.h"

class PLT_MediaController;

namespace UPNP
{

class CUPnPPlayerController;

class CUPnPPlayer
  : public IPlayer
{
public:
  CUPnPPlayer(IPlayerCallback& callback, const char* uuid);
  virtual ~CUPnPPlayer();

  virtual bool OpenFile(const CFileItem& file, const CPlayerOptions& options);
  virtual bool QueueNextFile(const CFileItem &file);
  virtual bool CloseFile();
  virtual bool IsPlaying() const;
  virtual void Pause();
  virtual bool IsPaused() const;
  virtual bool HasVideo() const { return false; }
  virtual bool HasAudio() const { return false; }
  virtual void Seek(bool bPlus, bool bLargeStep);
  virtual void SeekPercentage(float fPercent = 0);
  virtual float GetPercentage();
  virtual void SetVolume(float volume);
  virtual void GetAudioInfo( CStdString& strAudioInfo) {};
  virtual void GetVideoInfo( CStdString& strVideoInfo) {};
  virtual void GetGeneralInfo( CStdString& strVideoInfo) {};
  virtual bool CanRecord() { return false;};
  virtual bool IsRecording() { return false;};
  virtual bool Record(bool bOnOff) { return false;};

  virtual int  GetChapterCount()                               { return 0; }
  virtual int  GetChapter()                                    { return -1; }
  virtual void GetChapterName(CStdString& strChapterName)      { return; }
  virtual int  SeekChapter(int iChapter)                       { return -1; }

  virtual void SeekTime(__int64 iTime = 0);
  virtual int64_t GetTime();
  virtual int64_t GetTotalTime();
  virtual void ToFFRW(int iSpeed = 0){};

  virtual bool SkipNext(){return false;}
  virtual bool IsCaching() const {return false;};
  virtual int GetCacheLevel() const {return -1;};
  virtual void DoAudioWork();


  virtual CStdString GetPlayingTitle();

private:
  PLT_MediaController*   m_control;
  CUPnPPlayerController* m_delegate;
  CStdString             m_current_uri;
  CStdString             m_current_meta;
  bool                   m_started;
};

} /* namespace UPNP */
