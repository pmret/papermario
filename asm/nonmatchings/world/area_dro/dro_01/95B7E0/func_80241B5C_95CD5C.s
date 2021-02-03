.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B5C_95CD5C
/* 95CD5C 80241B5C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95CD60 80241B60 AFB00010 */  sw        $s0, 0x10($sp)
/* 95CD64 80241B64 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 95CD68 80241B68 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 95CD6C 80241B6C AFBF0018 */  sw        $ra, 0x18($sp)
/* 95CD70 80241B70 AFB10014 */  sw        $s1, 0x14($sp)
/* 95CD74 80241B74 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 95CD78 80241B78 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 95CD7C 80241B7C 10400003 */  beqz      $v0, .L80241B8C
/* 95CD80 80241B80 0080882D */   daddu    $s1, $a0, $zero
/* 95CD84 80241B84 24620001 */  addiu     $v0, $v1, 1
/* 95CD88 80241B88 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80241B8C:
/* 95CD8C 80241B8C 3C05F5DE */  lui       $a1, 0xf5de
/* 95CD90 80241B90 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 95CD94 80241B94 0C0B1EAF */  jal       get_variable
/* 95CD98 80241B98 0000202D */   daddu    $a0, $zero, $zero
/* 95CD9C 80241B9C 3C038024 */  lui       $v1, %hi(D_8024521C_96041C)
/* 95CDA0 80241BA0 00621821 */  addu      $v1, $v1, $v0
/* 95CDA4 80241BA4 9063521C */  lbu       $v1, %lo(D_8024521C_96041C)($v1)
/* 95CDA8 80241BA8 8E220084 */  lw        $v0, 0x84($s1)
/* 95CDAC 80241BAC 54430006 */  bnel      $v0, $v1, .L80241BC8
/* 95CDB0 80241BB0 AE200084 */   sw       $zero, 0x84($s1)
/* 95CDB4 80241BB4 24020001 */  addiu     $v0, $zero, 1
/* 95CDB8 80241BB8 AE220084 */  sw        $v0, 0x84($s1)
/* 95CDBC 80241BBC 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 95CDC0 80241BC0 24420001 */  addiu     $v0, $v0, 1
/* 95CDC4 80241BC4 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80241BC8:
/* 95CDC8 80241BC8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95CDCC 80241BCC 8FB10014 */  lw        $s1, 0x14($sp)
/* 95CDD0 80241BD0 8FB00010 */  lw        $s0, 0x10($sp)
/* 95CDD4 80241BD4 24020002 */  addiu     $v0, $zero, 2
/* 95CDD8 80241BD8 03E00008 */  jr        $ra
/* 95CDDC 80241BDC 27BD0020 */   addiu    $sp, $sp, 0x20
