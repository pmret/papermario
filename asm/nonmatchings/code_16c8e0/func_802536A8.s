.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802536A8
/* 181F88 802536A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 181F8C 802536AC AFBF0018 */  sw        $ra, 0x18($sp)
/* 181F90 802536B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 181F94 802536B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 181F98 802536B8 8C82000C */  lw        $v0, 0xc($a0)
/* 181F9C 802536BC 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 181FA0 802536C0 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 181FA4 802536C4 8C450000 */  lw        $a1, ($v0)
/* 181FA8 802536C8 0C0B1EAF */  jal       get_variable
/* 181FAC 802536CC 0200882D */   daddu    $s1, $s0, $zero
/* 181FB0 802536D0 1040000A */  beqz      $v0, .L802536FC
/* 181FB4 802536D4 2403FF7F */   addiu    $v1, $zero, -0x81
/* 181FB8 802536D8 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 181FBC 802536DC 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 181FC0 802536E0 92030092 */  lbu       $v1, 0x92($s0)
/* 181FC4 802536E4 8C440000 */  lw        $a0, ($v0)
/* 181FC8 802536E8 34630001 */  ori       $v1, $v1, 1
/* 181FCC 802536EC 34840080 */  ori       $a0, $a0, 0x80
/* 181FD0 802536F0 A2030092 */  sb        $v1, 0x92($s0)
/* 181FD4 802536F4 08094DC7 */  j         .L8025371C
/* 181FD8 802536F8 AC440000 */   sw       $a0, ($v0)
.L802536FC:
/* 181FDC 802536FC 92220092 */  lbu       $v0, 0x92($s1)
/* 181FE0 80253700 3C04800A */  lui       $a0, %hi(D_8009A650)
/* 181FE4 80253704 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* 181FE8 80253708 304200FE */  andi      $v0, $v0, 0xfe
/* 181FEC 8025370C A2220092 */  sb        $v0, 0x92($s1)
/* 181FF0 80253710 8C820000 */  lw        $v0, ($a0)
/* 181FF4 80253714 00431024 */  and       $v0, $v0, $v1
/* 181FF8 80253718 AC820000 */  sw        $v0, ($a0)
.L8025371C:
/* 181FFC 8025371C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 182000 80253720 8FB10014 */  lw        $s1, 0x14($sp)
/* 182004 80253724 8FB00010 */  lw        $s0, 0x10($sp)
/* 182008 80253728 24020002 */  addiu     $v0, $zero, 2
/* 18200C 8025372C 03E00008 */  jr        $ra
/* 182010 80253730 27BD0020 */   addiu    $sp, $sp, 0x20
