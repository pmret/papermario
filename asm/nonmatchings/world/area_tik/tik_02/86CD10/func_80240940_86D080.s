.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240940_86D080
/* 86D080 80240940 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 86D084 80240944 AFBF0014 */  sw        $ra, 0x14($sp)
/* 86D088 80240948 AFB00010 */  sw        $s0, 0x10($sp)
/* 86D08C 8024094C 8C82000C */  lw        $v0, 0xc($a0)
/* 86D090 80240950 8C450000 */  lw        $a1, ($v0)
/* 86D094 80240954 0C0B1EAF */  jal       get_variable
/* 86D098 80240958 8C900148 */   lw       $s0, 0x148($a0)
/* 86D09C 8024095C 82030004 */  lb        $v1, 4($s0)
/* 86D0A0 80240960 00021080 */  sll       $v0, $v0, 2
/* 86D0A4 80240964 00031880 */  sll       $v1, $v1, 2
/* 86D0A8 80240968 3C04800B */  lui       $a0, %hi(gCurrentEncounter+0x28)
/* 86D0AC 8024096C 00832021 */  addu      $a0, $a0, $v1
/* 86D0B0 80240970 8C840F38 */  lw        $a0, %lo(gCurrentEncounter+0x28)($a0)
/* 86D0B4 80240974 3C038024 */  lui       $v1, %hi(D_80241BAE)
/* 86D0B8 80240978 00621821 */  addu      $v1, $v1, $v0
/* 86D0BC 8024097C 94631BAE */  lhu       $v1, %lo(D_80241BAE)($v1)
/* 86D0C0 80240980 A4830044 */  sh        $v1, 0x44($a0)
/* 86D0C4 80240984 8FBF0014 */  lw        $ra, 0x14($sp)
/* 86D0C8 80240988 8FB00010 */  lw        $s0, 0x10($sp)
/* 86D0CC 8024098C 24020002 */  addiu     $v0, $zero, 2
/* 86D0D0 80240990 03E00008 */  jr        $ra
/* 86D0D4 80240994 27BD0018 */   addiu    $sp, $sp, 0x18
/* 86D0D8 80240998 00000000 */  nop
/* 86D0DC 8024099C 00000000 */  nop
