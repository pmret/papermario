#ifndef _AUDIO_PUBLIC_H_
#define _AUDIO_PUBLIC_H_

// 30450.c
void func_80055050(ALHeap* heap);
void func_80055068(u32 arg0);
//void func_80055110(BGMPlayer* player);
void func_8005513C(u32 arg0);
void snd_start_sound(s32 soundID, u8 volume, u8 pan);
void snd_start_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void snd_adjust_sound(s32 soundID, u8 volume, u8 pan);
void snd_adjust_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void snd_stop_sound(s32 soundID);
void func_800553F4(void);
void snd_start_sound_raw(s32 soundID, s16 volume, s16 pitchShift, s32 pan);
AuResult snd_ambient_80055448(s32 arg0);
AuResult snd_ambient_80055464(s32 arg0, s32 arg1);
AuResult snd_ambient_quick_fade_out(s32 arg0);
AuResult snd_ambient_slow_fade_out(s32 arg0, s32 arg1);
AuResult snd_ambient_8005553C(s32 arg0, s32 arg1);
AuResult snd_ambient_80055590(s32 arg0, s32 arg1);
AuResult snd_ambient_800555E4(s32 arg0);
AuResult snd_ambient_80055618(s32 arg0, s32 arg1);
AuResult snd_ambient_8005566C(s32 arg0, s32 arg1, s32 arg2);
AuResult snd_ambient_800556D0(s32 arg0);
AuResult snd_ambient_80055718(s32 arg0);
void snd_ambient_80055760(s32 arg0);
AuResult snd_ambient_800557CC(s32 arg0);
AuResult snd_ambient_80055848(s32 arg0);
AuResult snd_load_song(s32 songID, s32 playerIndex);
AuResult snd_start_song(s32 songName);
AuResult snd_start_song_variation(s32 songName, s32 variation);
AuResult au_song_stop_by_name(s32 songName);
void au_stop_songs(void);
AuResult au_song_is_playing(s32 songName);
AuResult snd_set_song_variation_fade(s32 songName, s32 variation, s32 fadeInTime, s32 startVolume, s32 endVolume);
AuResult snd_set_song_fade(s32 songName, s32 fadeInTime, s32 startVolume, s32 endVolume);
AuResult snd_set_song_variation_fade_time(s32 songName, s32 fadeTime, s32 variation);
AuResult func_80055AF0(s32 songName);
AuResult func_80055B28(s32 songName);
AuResult func_80055B80(s32 songName);
AuResult func_80055BB8(s32 songName, s32 fadeTime);
AuResult func_80055BF0(s32 songName);
AuResult func_80055C2C(s32 songName);
AuResult func_80055C64(s32 songName);
AuResult func_80055C94(s32 songName);
AuResult snd_set_song_variation(s32 songName, s32 variation);
//AuResult snd_song_get_playing_info(s32 songName, BGMHeader** outTrackData, BGMPlayer** outPlayer);
AuResult func_80055D38(s32 songName, f32 arg1);
AuResult func_80055D8C(s32 songName, s32 arg1);
AuResult snd_song_set_track_volumes(s32 songName, MusicTrackVols arg1);
AuResult snd_song_clear_track_volumes(s32 songName, MusicTrackVols arg1);
AuResult snd_song_set_track_vol_mute(s32 arg0, s32 arg1);
AuResult snd_song_set_track_vol_quiet(s32 arg0, s32 arg1);
AuResult snd_song_set_track_vol_full(s32 arg0, s32 arg1);
void bgm_set_proximity_mix_far(s32 songName, s32 mix);
void bgm_set_proximity_mix_near(s32 songName, s32 mix);
void bgm_set_proximity_mix_full(s32 songName, s32 mix);
void bgm_poll_music_events(u32** arg0, s32* arg1);
void bgm_flush_music_events(void);
void bgm_trigger_music_event(s32 arg0, s32 arg1, s32 arg2);
void bgm_clear_music_events(void);
//void func_80056144(AuCallback arg0, s32 arg1);
void audio_set_stereo(void);
void audio_set_mono(void);
void func_800561A4(s32 arg0);
void func_800561C4(s32 arg0);
void func_800561E4(s32 arg0);
void func_80056204(void);
void func_80056228(void);

// sfx.h
void sfx_reset_door_sounds(void);
void sfx_clear_sounds(void);
void sfx_clear_env_sounds(s16 playSounds);
void sfx_update_looping_sound_params(void);
void func_801497FC(s32 arg0);
s32 func_80149828(void);
void sfx_stop_env_sounds(void);
//SoundInstance* sfx_get_env_sound_instance(s32 soundID);
void sfx_play_sound_looping(s32 soundId, u8 volume, u8 pan, s16 pitchShift);
void sfx_register_looping_sound_at_position(s32 soundID, s32 flags, f32 x, f32 y, f32 z);
s32 sfx_adjust_env_sound_pos(s32 soundID, s32 sourceFlags, f32 x, f32 y, f32 z);
void func_80149A6C(s32 soundID, s32 keepPlaying);
void sfx_play_sound_with_params(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void sfx_adjust_env_sound_params(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void sfx_stop_sound(s32 soundID);
void sfx_play_sound(s32 soundID);
void sfx_play_sound_at_player(s32 soundID, s32 arg1);
void sfx_play_sound_at_npc(s32 soundID, s32 arg1, s32 npcID);
void sfx_play_sound_at_position(s32 soundID, s32 flags, f32 posX, f32 posY, f32 posZ);
void sfx_get_spatialized_sound_params(f32 x, f32 y, f32 z, s16* volume, s16* pan, s32 flags);
void sfx_compute_spatialized_sound_params_0(f32 x, f32 y, f32 z, s16* volume, s16* pan);
void sfx_compute_spatialized_sound_params_1(f32 x, f32 y, f32 z, s16* volume, s16* pan);
void sfx_compute_spatialized_sound_params_2(f32 x, f32 y, f32 z, s16* volume, s16* pan, s32 flags);

#endif
