#ifndef _AUDIO_PUBLIC_H_
#define _AUDIO_PUBLIC_H_

#include "audio.h"

// ----------------------------------------------------------------------------------
// snd_interface.c
// ----------------------------------------------------------------------------------
void snd_notify_engine_ready(ALHeap* heap);
void snd_legacy_sound_dispatch(u32 id);
//void snd_bgm_clear_legacy_commands(BGMPlayer* player);
void snd_bgm_enqueue_legacy_command(u32 cmd);
void snd_start_sound(s32 soundID, u8 volume, u8 pan);
void snd_start_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void snd_adjust_sound(s32 soundID, u8 volume, u8 pan);
void snd_adjust_sound_with_shift(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void snd_stop_sound(s32 soundID);
void snd_reset(void);
void snd_start_sound_raw(s32 soundID, s16 volume, s16 pitchShift, s32 pan);
AuResult snd_load_ambient(s32 arg0);
AuResult snd_ambient_play(s32 arg0, s32 arg1);
AuResult snd_ambient_stop_quick(s32 arg0);
AuResult snd_ambient_stop_slow(s32 arg0, s32 arg1);
AuResult snd_ambient_pause(s32 arg0, s32 arg1);
AuResult snd_ambient_resume(s32 arg0, s32 arg1);
AuResult snd_ambient_is_stopped(s32 arg0);
AuResult snd_ambient_fade_out(s32 arg0, s32 arg1);
AuResult snd_ambient_set_volume(s32 arg0, s32 arg1, s32 arg2);
AuResult snd_ambient_disable(s32 arg0);
AuResult snd_ambient_enable(s32 arg0);
void snd_ambient_radio_setup(s32 arg0);
AuResult snd_ambient_radio_stop(s32 arg0);
AuResult snd_ambient_radio_select(s32 arg0);
/// return value may be either an AuResult error code OR a valid songName
AuResult snd_song_load(s32 songID, s32 playerIndex);
AuResult snd_song_request_play_default(s32 songName);
AuResult snd_song_request_play(s32 songName, s32 variation);
AuResult snd_song_stop(s32 songName);
void snd_song_stop_all(void);
AuResult snd_song_is_playing(s32 songName);
AuResult snd_song_request_fade_in(s32 songName, s32 variation, s32 fadeInTime, s32 startVolume, s32 endVolume);
AuResult snd_song_request_fade_in_default(s32 songName, s32 fadeInTime, s32 startVolume, s32 endVolume);
AuResult snd_song_request_fade_out(s32 songName, s32 fadeTime, AuCallback callback);
AuResult snd_song_push_stop(s32 songName);
AuResult snd_song_request_pop(s32 songName);
AuResult snd_song_request_snapshot(s32 songName);
AuResult snd_song_request_push_fade_out(s32 songName, s32 fadeTime);
AuResult snd_song_request_pause(s32 songName);
AuResult snd_song_request_unpause(s32 songName);
AuResult snd_song_set_volume_quiet(s32 songName);
AuResult snd_song_set_volume_full(s32 songName);
AuResult snd_song_set_linked_mode(s32 songName, bool mode);
//AuResult snd_song_get_playing_info(s32 songName, BGMHeader** outTrackData, BGMPlayer** outPlayer);
AuResult snd_song_set_playback_rate(s32 songName, f32 arg1);
/*
AuResult snd_song_set_detune(s32 songName, s32 arg1);
AuResult snd_song_set_track_volumes(s32 songName, MusicTrackVols arg1);
AuResult snd_song_clear_track_volumes(s32 songName, MusicTrackVols arg1);
AuResult snd_song_set_track_vol_mute(s32 arg0, s32 arg1);
AuResult snd_song_set_track_vol_quiet(s32 arg0, s32 arg1);
AuResult snd_song_set_track_vol_full(s32 arg0, s32 arg1);
void snd_song_set_proximity_mix_far(s32 songName, s32 mix);
void snd_song_set_proximity_mix_near(s32 songName, s32 mix);
void snd_song_set_proximity_mix_full(s32 songName, s32 mix);
*/
void snd_song_poll_music_events(u32** arg0, s32* arg1);
void snd_song_flush_music_events(void);
void snd_song_trigger_music_event(s32 playerID, s32 trackIndex, s32 eventInfo);
void snd_song_clear_music_events(void);
//void snd_register_callback(AuCallback func, s32 index);
void snd_set_stereo(void);
void snd_set_mono(void);
void snd_set_bgm_volume(VolumeLevels volume);
void snd_set_sfx_volume(VolumeLevels volume);
void snd_set_sfx_reverb_type(s32 arg0);
void snd_enable_sfx(void);
void snd_disable_sfx(void);

// ----------------------------------------------------------------------------------
// bgm_control.c
// ----------------------------------------------------------------------------------
AuResult bgm_set_track_volumes(s32 playerIndex, s16 trackVolSet);
AuResult bgm_clear_track_volumes(s32 playerIndex, s16 trackVolSet);
AuResult bgm_set_linked_mode(s32 playerIndex, b16 mode);
void bgm_quiet_max_volume(void);
void bgm_reset_max_volume(void);
void bgm_reset_volume(void);
s32 bgm_init_music_players(void);
s32 bgm_set_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeOutTime, s16 volume);
void bgm_set_battle_song(s32, s32);
void bgm_push_battle_song(void);
s32 bgm_adjust_proximity(s32 playerIndex, s32 arg1, s16 arg2);
bool bgm_fade_in_song(s32 playerIndex, s32 songID, s32 variation, s32 fadeInTime, s16 arg4, s16 arg5);

void bgm_update_music_control(void);
bool bgm_is_any_song_playing(void);
void bgm_reset_sequence_players(void);
void bgm_pop_song(void);
void bgm_push_song(s32 songID, s32 variation);
void bgm_pop_battle_song(void);

// ----------------------------------------------------------------------------------
// sfx_control.c
// ----------------------------------------------------------------------------------
void sfx_reset_door_sounds(void);
void sfx_clear_sounds(void);
void sfx_clear_env_sounds(s16 playSounds);
void sfx_update_env_sound_params(void);
void sfx_set_reverb_mode(s32 arg0);
s32 sfx_get_reverb_mode(void);
void sfx_stop_env_sounds(void);
//SoundInstance* sfx_get_env_sound_instance(s32 soundID);
void sfx_play_sound_looping(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void sfx_register_looping_sound_at_position(s32 soundID, s32 flags, f32 x, f32 y, f32 z);
s32 sfx_adjust_env_sound_pos(s32 soundID, s32 sourceFlags, f32 x, f32 y, f32 z);
void sfx_stop_tracking_env_sound_pos(s32 soundID, s32 keepPlaying);
void sfx_play_sound_with_params(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void sfx_adjust_env_sound_params(s32 soundID, u8 volume, u8 pan, s16 pitchShift);
void sfx_stop_sound(s32 soundID);
void sfx_play_sound(s32 soundID);
void sfx_play_sound_at_player(s32 soundID, s32 arg1);
void sfx_play_sound_at_npc(s32 soundID, s32 arg1, s32 npcID);
void sfx_play_sound_at_position(s32 soundID, s32 flags, f32 posX, f32 posY, f32 posZ);
void sfx_get_spatialized_sound_params(f32 x, f32 y, f32 z, s16* volume, s16* pan, s32 flags);
void sfx_compute_spatialized_sound_params_ignore_depth(f32 x, f32 y, f32 z, s16* volume, s16* pan);
void sfx_compute_spatialized_sound_params_with_depth(f32 x, f32 y, f32 z, s16* volume, s16* pan);
void sfx_compute_spatialized_sound_params_full(f32 x, f32 y, f32 z, s16* volume, s16* pan, s32 flags);

#endif
