.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024247C_9D949C
/* 9D949C 8024247C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D94A0 80242480 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D94A4 80242484 0080882D */  daddu     $s1, $a0, $zero
/* 9D94A8 80242488 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D94AC 8024248C AFB00010 */  sw        $s0, 0x10($sp)
/* 9D94B0 80242490 8E30000C */  lw        $s0, 0xc($s1)
/* 9D94B4 80242494 8E050000 */  lw        $a1, ($s0)
/* 9D94B8 80242498 0C0B1EAF */  jal       get_variable
/* 9D94BC 8024249C 26100004 */   addiu    $s0, $s0, 4
/* 9D94C0 802424A0 0220202D */  daddu     $a0, $s1, $zero
/* 9D94C4 802424A4 8E050000 */  lw        $a1, ($s0)
/* 9D94C8 802424A8 0C0B210B */  jal       get_float_variable
/* 9D94CC 802424AC 0040802D */   daddu    $s0, $v0, $zero
/* 9D94D0 802424B0 24020002 */  addiu     $v0, $zero, 2
/* 9D94D4 802424B4 00501804 */  sllv      $v1, $s0, $v0
/* 9D94D8 802424B8 00701821 */  addu      $v1, $v1, $s0
/* 9D94DC 802424BC 00431804 */  sllv      $v1, $v1, $v0
/* 9D94E0 802424C0 00701823 */  subu      $v1, $v1, $s0
/* 9D94E4 802424C4 000320C0 */  sll       $a0, $v1, 3
/* 9D94E8 802424C8 00641821 */  addu      $v1, $v1, $a0
/* 9D94EC 802424CC 000318C0 */  sll       $v1, $v1, 3
/* 9D94F0 802424D0 3C01800B */  lui       $at, 0x800b
/* 9D94F4 802424D4 00230821 */  addu      $at, $at, $v1
/* 9D94F8 802424D8 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 9D94FC 802424DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D9500 802424E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D9504 802424E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9508 802424E8 03E00008 */  jr        $ra
/* 9D950C 802424EC 27BD0020 */   addiu    $sp, $sp, 0x20
