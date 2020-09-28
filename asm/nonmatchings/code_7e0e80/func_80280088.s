.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80280088
/* 7E0F08 80280088 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E0F0C 8028008C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E0F10 80280090 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7E0F14 80280094 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E0F18 80280098 00C0902D */  daddu     $s2, $a2, $zero
/* 7E0F1C 8028009C AFB10014 */  sw        $s1, 0x14($sp)
/* 7E0F20 802800A0 00E0882D */  daddu     $s1, $a3, $zero
/* 7E0F24 802800A4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7E0F28 802800A8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7E0F2C 802800AC AFB00010 */  sw        $s0, 0x10($sp)
/* 7E0F30 802800B0 8C500144 */  lw        $s0, 0x144($v0)
/* 7E0F34 802800B4 00041080 */  sll       $v0, $a0, 2
/* 7E0F38 802800B8 8E030010 */  lw        $v1, 0x10($s0)
/* 7E0F3C 802800BC 00A0202D */  daddu     $a0, $a1, $zero
/* 7E0F40 802800C0 8C630018 */  lw        $v1, 0x18($v1)
/* 7E0F44 802800C4 00431021 */  addu      $v0, $v0, $v1
/* 7E0F48 802800C8 8C530000 */  lw        $s3, ($v0)
/* 7E0F4C 802800CC 0C0496CF */  jal       set_message_string
/* 7E0F50 802800D0 0000282D */   daddu    $a1, $zero, $zero
/* 7E0F54 802800D4 0240202D */  daddu     $a0, $s2, $zero
/* 7E0F58 802800D8 0C0496FA */  jal       set_message_value
/* 7E0F5C 802800DC 24050001 */   addiu    $a1, $zero, 1
/* 7E0F60 802800E0 1A200005 */  blez      $s1, .L802800F8
/* 7E0F64 802800E4 0220202D */   daddu    $a0, $s1, $zero
/* 7E0F68 802800E8 0C0496FA */  jal       set_message_value
/* 7E0F6C 802800EC 24050002 */   addiu    $a1, $zero, 2
/* 7E0F70 802800F0 080A0047 */  j         .L8028011C
/* 7E0F74 802800F4 00000000 */   nop      
.L802800F8:
/* 7E0F78 802800F8 3C048015 */  lui       $a0, 0x8015
/* 7E0F7C 802800FC 2484C290 */  addiu     $a0, $a0, -0x3d70
/* 7E0F80 80280100 24020001 */  addiu     $v0, $zero, 1
/* 7E0F84 80280104 16420003 */  bne       $s2, $v0, .L80280114
/* 7E0F88 80280108 00000000 */   nop      
/* 7E0F8C 8028010C 3C048015 */  lui       $a0, 0x8015
/* 7E0F90 80280110 2484C294 */  addiu     $a0, $a0, -0x3d6c
.L80280114:
/* 7E0F94 80280114 0C0496CF */  jal       set_message_string
/* 7E0F98 80280118 24050002 */   addiu    $a1, $zero, 2
.L8028011C:
/* 7E0F9C 8028011C 3C048028 */  lui       $a0, 0x8028
/* 7E0FA0 80280120 24843E80 */  addiu     $a0, $a0, 0x3e80
/* 7E0FA4 80280124 24050001 */  addiu     $a1, $zero, 1
/* 7E0FA8 80280128 0C0B0CF8 */  jal       start_script
/* 7E0FAC 8028012C 0000302D */   daddu    $a2, $zero, $zero
/* 7E0FB0 80280130 0040202D */  daddu     $a0, $v0, $zero
/* 7E0FB4 80280134 AC930084 */  sw        $s3, 0x84($a0)
/* 7E0FB8 80280138 8E020010 */  lw        $v0, 0x10($s0)
/* 7E0FBC 8028013C 8C420000 */  lw        $v0, ($v0)
/* 7E0FC0 80280140 AC820088 */  sw        $v0, 0x88($a0)
/* 7E0FC4 80280144 8E020010 */  lw        $v0, 0x10($s0)
/* 7E0FC8 80280148 8C420008 */  lw        $v0, 8($v0)
/* 7E0FCC 8028014C AC82008C */  sw        $v0, 0x8c($a0)
/* 7E0FD0 80280150 8E030010 */  lw        $v1, 0x10($s0)
/* 7E0FD4 80280154 8C820144 */  lw        $v0, 0x144($a0)
/* 7E0FD8 80280158 8C630004 */  lw        $v1, 4($v1)
/* 7E0FDC 8028015C AC830090 */  sw        $v1, 0x90($a0)
/* 7E0FE0 80280160 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7E0FE4 80280164 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7E0FE8 80280168 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E0FEC 8028016C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E0FF0 80280170 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E0FF4 80280174 03E00008 */  jr        $ra
/* 7E0FF8 80280178 27BD0028 */   addiu    $sp, $sp, 0x28
