.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80043F58
/* 1F358 80043F58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1F35C 80043F5C AFB10014 */  sw        $s1, 0x14($sp)
/* 1F360 80043F60 0080882D */  daddu     $s1, $a0, $zero
/* 1F364 80043F64 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1F368 80043F68 AFB00010 */  sw        $s0, 0x10($sp)
/* 1F36C 80043F6C 8E30000C */  lw        $s0, 0xc($s1)
/* 1F370 80043F70 54A00001 */  bnel      $a1, $zero, .L80043F78
/* 1F374 80043F74 AE200070 */   sw       $zero, 0x70($s1)
.L80043F78:
/* 1F378 80043F78 8E240070 */  lw        $a0, 0x70($s1)
/* 1F37C 80043F7C 10800005 */  beqz      $a0, .L80043F94
/* 1F380 80043F80 24020001 */   addiu    $v0, $zero, 1
/* 1F384 80043F84 10820014 */  beq       $a0, $v0, .L80043FD8
/* 1F388 80043F88 0000102D */   daddu    $v0, $zero, $zero
/* 1F38C 80043F8C 08010FFB */  j         .L80043FEC
/* 1F390 80043F90 00000000 */   nop
.L80043F94:
/* 1F394 80043F94 8E050000 */  lw        $a1, ($s0)
/* 1F398 80043F98 26100004 */  addiu     $s0, $s0, 4
/* 1F39C 80043F9C 0C0B1EAF */  jal       func_802C7ABC
/* 1F3A0 80043FA0 0220202D */   daddu    $a0, $s1, $zero
/* 1F3A4 80043FA4 0220202D */  daddu     $a0, $s1, $zero
/* 1F3A8 80043FA8 8E050000 */  lw        $a1, ($s0)
/* 1F3AC 80043FAC 0C0B1EAF */  jal       func_802C7ABC
/* 1F3B0 80043FB0 0040802D */   daddu    $s0, $v0, $zero
/* 1F3B4 80043FB4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 1F3B8 80043FB8 8C63417C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 1F3BC 80043FBC 0200202D */  daddu     $a0, $s0, $zero
/* 1F3C0 80043FC0 8465008C */  lh        $a1, 0x8c($v1)
/* 1F3C4 80043FC4 0C00F8CE */  jal       func_8003E338
/* 1F3C8 80043FC8 0040302D */   daddu    $a2, $v0, $zero
/* 1F3CC 80043FCC 24020001 */  addiu     $v0, $zero, 1
/* 1F3D0 80043FD0 08010FFA */  j         .L80043FE8
/* 1F3D4 80043FD4 AE220070 */   sw       $v0, 0x70($s1)
.L80043FD8:
/* 1F3D8 80043FD8 3C03800A */  lui       $v1, %hi(D_8009A5E0)
/* 1F3DC 80043FDC 8C63A5E0 */  lw        $v1, %lo(D_8009A5E0)($v1)
/* 1F3E0 80043FE0 14640002 */  bne       $v1, $a0, .L80043FEC
/* 1F3E4 80043FE4 24020002 */   addiu    $v0, $zero, 2
.L80043FE8:
/* 1F3E8 80043FE8 0000102D */  daddu     $v0, $zero, $zero
.L80043FEC:
/* 1F3EC 80043FEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1F3F0 80043FF0 8FB10014 */  lw        $s1, 0x14($sp)
/* 1F3F4 80043FF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 1F3F8 80043FF8 03E00008 */  jr        $ra
/* 1F3FC 80043FFC 27BD0020 */   addiu    $sp, $sp, 0x20
