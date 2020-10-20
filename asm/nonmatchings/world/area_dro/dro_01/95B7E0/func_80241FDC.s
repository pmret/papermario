.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FDC
/* 95D1DC 80241FDC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95D1E0 80241FE0 AFB10014 */  sw        $s1, 0x14($sp)
/* 95D1E4 80241FE4 0080882D */  daddu     $s1, $a0, $zero
/* 95D1E8 80241FE8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 95D1EC 80241FEC AFB00010 */  sw        $s0, 0x10($sp)
/* 95D1F0 80241FF0 8E30000C */  lw        $s0, 0xc($s1)
/* 95D1F4 80241FF4 8E050000 */  lw        $a1, ($s0)
/* 95D1F8 80241FF8 0C0B1EAF */  jal       get_variable
/* 95D1FC 80241FFC 26100004 */   addiu    $s0, $s0, 4
/* 95D200 80242000 0220202D */  daddu     $a0, $s1, $zero
/* 95D204 80242004 8E050000 */  lw        $a1, ($s0)
/* 95D208 80242008 0C0B210B */  jal       get_float_variable
/* 95D20C 8024200C 0040802D */   daddu    $s0, $v0, $zero
/* 95D210 80242010 24020002 */  addiu     $v0, $zero, 2
/* 95D214 80242014 00501804 */  sllv      $v1, $s0, $v0
/* 95D218 80242018 00701821 */  addu      $v1, $v1, $s0
/* 95D21C 8024201C 00431804 */  sllv      $v1, $v1, $v0
/* 95D220 80242020 00701823 */  subu      $v1, $v1, $s0
/* 95D224 80242024 000320C0 */  sll       $a0, $v1, 3
/* 95D228 80242028 00641821 */  addu      $v1, $v1, $a0
/* 95D22C 8024202C 000318C0 */  sll       $v1, $v1, 3
/* 95D230 80242030 3C01800B */  lui       $at, 0x800b
/* 95D234 80242034 00230821 */  addu      $at, $at, $v1
/* 95D238 80242038 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 95D23C 8024203C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95D240 80242040 8FB10014 */  lw        $s1, 0x14($sp)
/* 95D244 80242044 8FB00010 */  lw        $s0, 0x10($sp)
/* 95D248 80242048 03E00008 */  jr        $ra
/* 95D24C 8024204C 27BD0020 */   addiu    $sp, $sp, 0x20
