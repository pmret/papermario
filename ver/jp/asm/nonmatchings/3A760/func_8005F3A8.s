.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F3A8
/* 3A7A8 8005F3A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A7AC 8005F3AC AFBF0014 */  sw        $ra, 0x14($sp)
/* 3A7B0 8005F3B0 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A7B4 8005F3B4 8C90000C */  lw        $s0, 0xc($a0)
/* 3A7B8 8005F3B8 8E050000 */  lw        $a1, ($s0)
/* 3A7BC 8005F3BC AE00000C */  sw        $zero, 0xc($s0)
/* 3A7C0 8005F3C0 8CA60008 */  lw        $a2, 8($a1)
/* 3A7C4 8005F3C4 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3A7C8 8005F3C8 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3A7CC 8005F3CC 0C01A45C */  jal       func_80069170
/* 3A7D0 8005F3D0 00000000 */   nop
/* 3A7D4 8005F3D4 0040182D */  daddu     $v1, $v0, $zero
/* 3A7D8 8005F3D8 14600002 */  bnez      $v1, .L8005F3E4
/* 3A7DC 8005F3DC 24020001 */   addiu    $v0, $zero, 1
/* 3A7E0 8005F3E0 AE02000C */  sw        $v0, 0xc($s0)
.L8005F3E4:
/* 3A7E4 8005F3E4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3A7E8 8005F3E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A7EC 8005F3EC 0060102D */  daddu     $v0, $v1, $zero
/* 3A7F0 8005F3F0 03E00008 */  jr        $ra
/* 3A7F4 8005F3F4 27BD0018 */   addiu    $sp, $sp, 0x18
