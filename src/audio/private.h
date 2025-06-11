#ifndef _AUDIO_PRIVATE_H_
#define _AUDIO_PRIVATE_H_

// ----------------------------------------------------------------------------------
// load_banks.c
// ----------------------------------------------------------------------------------
void au_load_BK_headers(AuGlobals* arg0, ALHeap*);

// ----------------------------------------------------------------------------------
// mseq_player.c
// ----------------------------------------------------------------------------------
void au_mseq_manager_init(AmbienceManager* arg0, s8 arg1, s8 reverbType, AuGlobals* arg3);
AuResult au_mseq_check_player_index(u32 arg0);
void au_mseq_load_tracks_fade(s32 arg0, s32 arg1);
void au_mseq_set_disabled(s32 arg0, s32 arg1);
AuResult au_mseq_start(s32 arg0, s32 arg1);
void au_mseq_fade_setup(AmbiencePlayer* arg0);
void au_mseq_pause(s32 arg0, s32 arg1);
void au_mseq_resume(s32 arg0, s32 arg1);
void au_mseq_stop_quick(s32 arg0);
void au_mseq_stop_slow(s32 arg0, s32 arg1);
void au_mseq_set_volume(s32 arg0, s32 arg1, s32 arg2);
AuResult au_mseq_check_stopped(s32 arg0);
void au_mseq_play_sequence(AmbienceManager* arg0, MSEQHeader* mseq, s32 index);
void au_mseq_manager_audio_frame_update(AmbienceManager* arg0);
void au_mseq_load_track_fade_info(AmbienceManager* manager, AmbiencePlayer* lambda);
void au_mseq_player_update(AmbienceManager* manager, AmbiencePlayer* lambda);
u8 au_mseq_read_next(AmbiencePlayer* arg0);
void au_mseq_player_stop(AmbienceManager* arg0, AmbiencePlayer* arg1);
void au_mseq_save_voices(AmbienceManager* arg0, AmbiencePlayer* lambda);
void au_mseq_restore_voices(AmbienceManager* manager, AmbiencePlayer* lambda);

// ----------------------------------------------------------------------------------
// sfx_player.c
// ----------------------------------------------------------------------------------
void au_sfx_init(SoundManager* manager, u8 arg1, u8 arg2, AuGlobals* arg3, u8 arg4);
void au_sfx_load_groups_from_SEF(SoundManager* sndMgr);
void au_sfx_clear_queue(SoundManager* manager);
void au_sfx_enqueue_event(SoundManager* manager, u32 soundID, s16 volume, s16 pitchShift, u8 pan);
void au_sfx_begin_video_frame(SoundManager* manager);
s32 au_sfx_set_reverb_type(SoundManager* manager, s32 arg1);
void au_sfx_set_state(SoundManager* manager, s32 arg1);
void au_sfx_try_sound(SoundManager* manager, SoundRequest* request, SoundManagerCustomCmdList*);
s16 au_sfx_manager_audio_frame_update(SoundManager* manager);

// ----------------------------------------------------------------------------------
// bgm_player.c
// ----------------------------------------------------------------------------------
void au_bgm_begin_video_frame(BGMPlayer* player);
BGMPlayer* au_bgm_get_player_with_song_name(s32 songString);
AuResult au_bgm_process_init_song(SongStartRequest* event);
AuResult au_bgm_stop_song(s32 songName);
void au_bgm_stop_all(void);
AuResult au_bgm_is_song_playing(s32 songName);
b32 au_bgm_player_is_active(BGMPlayer* player);
AuResult au_bgm_process_fade_out(SongFadeOutRequest* s);
AuResult au_bgm_complete_push(s32 songName);
AuResult au_bgm_process_suspend(SongSuspendRequest* update, b32 skipStop);
AuResult au_bgm_process_resume(SongResumeRequest* update);
void au_bgm_restore_copied_player(AuGlobals* globals);
AuResult au_bgm_adjust_volume(SongStartRequest* update);
void au_bgm_player_init(BGMPlayer* player, s32 arg1, s32 arg2, AuGlobals* arg3);
void au_bgm_set_effect_indices(BGMPlayer* player, u8* list);
void au_bgm_update_fade(BGMPlayer* player);
void au_bgm_update_bus_volumes(BGMPlayer* arg0);
s32 au_bgm_player_audio_frame_update(BGMPlayer* player);
void au_bgm_player_initialize(BGMPlayer* player);
void au_bgm_clear_custom_note_press(BGMPlayer* player, s32 arg1);
void au_bgm_set_tick_resolution(BGMPlayer* player, s32 sampleRate, u32 resolution);
void au_bgm_player_read_composition(BGMPlayer* player);
void au_bgm_end_composition_loop(BGMPlayer* player, u32 cmd);
void au_bgm_load_phrase(BGMPlayer* player, u32 cmd);
void au_bgm_player_update_stop(BGMPlayer* player);
void au_bgm_player_update_playing(BGMPlayer *player);
void au_BGMCmd_E0_MasterTempo(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_E1_MasterVolume(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_E2_MasterDetune(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_E3(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_E6_MasterEffect(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_E4_MasterTempoFade(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_E5_MasterVolumeFade(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_E8_TrackOverridePatch(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_E9_InstrumentVolume(BGMPlayer* arg0, BGMPlayerTrack* track);
void au_BGMCmd_F6_InstrumentVolumeLerp(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_EA_InstrumentPan(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_EB_InstrumentReverb(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_EC_TrackVolume(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_ED_InstrumentCoarseTune(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_EE_InstrumentFineTune(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_EC_TrackDetune(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_F0_TrackTremolo(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_F1_TrackTremoloRate(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_F2_TrackTremoloDepth(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_F3_TrackTremoloStop(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_F4_SubTrackRandomPan(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_F5_UseInstrument(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_F7_ReverbType(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_FD_EventTrigger(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_FE_Detour(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_FC_Branch(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_FF_Special(BGMPlayer* player, BGMPlayerTrack* track);
void au_BGMCmd_NOP(BGMPlayer* player, BGMPlayerTrack* track);
void au_bgm_set_proximity_mix(s32 songName, u32 mix);
void au_bgm_set_playback_rate(BGMPlayer* player, f32 arg1);
void au_bgm_player_set_detune(BGMPlayer* player, s32 arg1);
void au_bgm_change_track_volume(BGMPlayer* player, s32 trackIdx, s16 arg2, u8 arg3);
void au_bgm_set_track_volumes(BGMPlayer* player, u8* arg1, s32 arg2);
void au_bgm_set_prox_mix_fade(BGMPlayer* player, BGMPlayerTrack* track, s32 target, s32 duration);
void au_bgm_reset_all_voices(BGMPlayer* player);
AuResult au_bgm_set_linked_tracks(SongSwapLinkedRequest* arg0);

// ----------------------------------------------------------------------------------
// snd_interface.c
// ----------------------------------------------------------------------------------
void snd_bgm_clear_legacy_commands(BGMPlayer* player);
/*
void snd_notify_engine_ready(ALHeap* heap);
void snd_legacy_sound_dispatch(u32 arg0);
void snd_bgm_clear_legacy_commands(BGMPlayer* player);
void snd_bgm_enqueue_legacy_command(u32 arg0);
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
AuResult snd_song_set_linked_mode(s32 songName, b32 mode);
*/
AuResult snd_song_get_playing_info(s32 songName, BGMHeader** outTrackData, BGMPlayer** outPlayer);
/*
AuResult snd_song_set_playback_rate(s32 songName, f32 arg1);
*/
AuResult snd_song_set_detune(s32 songName, s32 arg1);
AuResult snd_song_set_track_volumes(s32 songName, MusicTrackVols arg1);
AuResult snd_song_clear_track_volumes(s32 songName, MusicTrackVols arg1);
AuResult snd_song_set_track_vol_mute(s32 arg0, s32 arg1);
AuResult snd_song_set_track_vol_quiet(s32 arg0, s32 arg1);
AuResult snd_song_set_track_vol_full(s32 arg0, s32 arg1);
void snd_song_set_proximity_mix_far(s32 songName, s32 mix);
void snd_song_set_proximity_mix_near(s32 songName, s32 mix);
void snd_song_set_proximity_mix_full(s32 songName, s32 mix);
/*
void snd_song_poll_music_events(u32** arg0, s32* arg1);
void snd_song_flush_music_events(void);
void snd_song_trigger_music_event(s32 playerID, s32 trackIndex, s32 eventInfo);
void snd_song_clear_music_events(void);
void snd_register_callback(AuCallback func, s32 index);
void snd_set_stereo(void);
void snd_set_mono(void);
void snd_set_bgm_volume(s32 arg0);
void snd_set_sfx_volume(s32 arg0);
void snd_set_sfx_reverb_type(s32 arg0);
void snd_enable_sfx(void);
void snd_disable_sfx(void);
*/

// ----------------------------------------------------------------------------------
// sfx_control.c
// ----------------------------------------------------------------------------------
/*
void sfx_reset_door_sounds(void);
void sfx_clear_sounds(void);
void sfx_clear_env_sounds(s16 playSounds);
void sfx_update_env_sound_params(void);
void sfx_set_reverb_mode(s32 arg0);
s32 sfx_get_reverb_mode(void);
void sfx_stop_env_sounds(void);
*/
SoundInstance* sfx_get_env_sound_instance(s32 soundID);
/*
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
*/

#endif
