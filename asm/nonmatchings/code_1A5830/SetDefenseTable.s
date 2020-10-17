.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetDefenseTable
/* 1AB354 8027CA74 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AB358 8027CA78 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AB35C 8027CA7C 0080882D */  daddu     $s1, $a0, $zero
/* 1AB360 8027CA80 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1AB364 8027CA84 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AB368 8027CA88 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AB36C 8027CA8C 8E30000C */  lw        $s0, 0xc($s1)
/* 1AB370 8027CA90 8E050000 */  lw        $a1, ($s0)
/* 1AB374 8027CA94 0C0B1EAF */  jal       get_variable
/* 1AB378 8027CA98 26100004 */   addiu    $s0, $s0, 4
/* 1AB37C 8027CA9C 0040902D */  daddu     $s2, $v0, $zero
/* 1AB380 8027CAA0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AB384 8027CAA4 16420002 */  bne       $s2, $v0, .L8027CAB0
/* 1AB388 8027CAA8 00000000 */   nop      
/* 1AB38C 8027CAAC 8E320148 */  lw        $s2, 0x148($s1)
.L8027CAB0:
/* 1AB390 8027CAB0 8E050000 */  lw        $a1, ($s0)
/* 1AB394 8027CAB4 26100004 */  addiu     $s0, $s0, 4
/* 1AB398 8027CAB8 0C0B1EAF */  jal       get_variable
/* 1AB39C 8027CABC 0220202D */   daddu    $a0, $s1, $zero
/* 1AB3A0 8027CAC0 0220202D */  daddu     $a0, $s1, $zero
/* 1AB3A4 8027CAC4 8E050000 */  lw        $a1, ($s0)
/* 1AB3A8 8027CAC8 0C0B1EAF */  jal       get_variable
/* 1AB3AC 8027CACC 0040882D */   daddu    $s1, $v0, $zero
/* 1AB3B0 8027CAD0 0240202D */  daddu     $a0, $s2, $zero
/* 1AB3B4 8027CAD4 0C09A75B */  jal       get_actor
/* 1AB3B8 8027CAD8 0040802D */   daddu    $s0, $v0, $zero
/* 1AB3BC 8027CADC 0040202D */  daddu     $a0, $v0, $zero
/* 1AB3C0 8027CAE0 0C099117 */  jal       get_actor_part
/* 1AB3C4 8027CAE4 0220282D */   daddu    $a1, $s1, $zero
/* 1AB3C8 8027CAE8 AC500078 */  sw        $s0, 0x78($v0)
/* 1AB3CC 8027CAEC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1AB3D0 8027CAF0 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AB3D4 8027CAF4 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AB3D8 8027CAF8 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AB3DC 8027CAFC 24020002 */  addiu     $v0, $zero, 2
/* 1AB3E0 8027CB00 03E00008 */  jr        $ra
/* 1AB3E4 8027CB04 27BD0020 */   addiu    $sp, $sp, 0x20
