.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_start_song_variation
/* 30D70 80055970 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30D74 80055974 AFB00030 */  sw        $s0, 0x30($sp)
/* 30D78 80055978 3C108008 */  lui       $s0, %hi(D_80078DB0)
/* 30D7C 8005597C 26108DB0 */  addiu     $s0, $s0, %lo(D_80078DB0)
/* 30D80 80055980 24020001 */  addiu     $v0, $zero, 1
/* 30D84 80055984 AFBF0034 */  sw        $ra, 0x34($sp)
/* 30D88 80055988 AE020000 */  sw        $v0, ($s0)
/* 30D8C 8005598C 2402007F */  addiu     $v0, $zero, 0x7f
/* 30D90 80055990 AFA40010 */  sw        $a0, 0x10($sp)
/* 30D94 80055994 27A40010 */  addiu     $a0, $sp, 0x10
/* 30D98 80055998 AFA00014 */  sw        $zero, 0x14($sp)
/* 30D9C 8005599C AFA20018 */  sw        $v0, 0x18($sp)
/* 30DA0 800559A0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 30DA4 800559A4 AFA50020 */  sw        $a1, 0x20($sp)
/* 30DA8 800559A8 0C0135F8 */  jal       snd_dispatch_bgm_player_event
/* 30DAC 800559AC AFA00024 */   sw       $zero, 0x24($sp)
/* 30DB0 800559B0 AE000000 */  sw        $zero, ($s0)
/* 30DB4 800559B4 8FBF0034 */  lw        $ra, 0x34($sp)
/* 30DB8 800559B8 8FB00030 */  lw        $s0, 0x30($sp)
/* 30DBC 800559BC 03E00008 */  jr        $ra
/* 30DC0 800559C0 27BD0038 */   addiu    $sp, $sp, 0x38
