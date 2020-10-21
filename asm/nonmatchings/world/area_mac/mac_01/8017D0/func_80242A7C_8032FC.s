.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A7C_8032FC
/* 8032FC 80242A7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 803300 80242A80 AFB10014 */  sw        $s1, 0x14($sp)
/* 803304 80242A84 0080882D */  daddu     $s1, $a0, $zero
/* 803308 80242A88 AFBF0018 */  sw        $ra, 0x18($sp)
/* 80330C 80242A8C AFB00010 */  sw        $s0, 0x10($sp)
/* 803310 80242A90 8E30000C */  lw        $s0, 0xc($s1)
/* 803314 80242A94 8E050000 */  lw        $a1, ($s0)
/* 803318 80242A98 0C0B1EAF */  jal       get_variable
/* 80331C 80242A9C 26100004 */   addiu    $s0, $s0, 4
/* 803320 80242AA0 0220202D */  daddu     $a0, $s1, $zero
/* 803324 80242AA4 8E050000 */  lw        $a1, ($s0)
/* 803328 80242AA8 0C0B210B */  jal       get_float_variable
/* 80332C 80242AAC 0040802D */   daddu    $s0, $v0, $zero
/* 803330 80242AB0 24020002 */  addiu     $v0, $zero, 2
/* 803334 80242AB4 00501804 */  sllv      $v1, $s0, $v0
/* 803338 80242AB8 00701821 */  addu      $v1, $v1, $s0
/* 80333C 80242ABC 00431804 */  sllv      $v1, $v1, $v0
/* 803340 80242AC0 00701823 */  subu      $v1, $v1, $s0
/* 803344 80242AC4 000320C0 */  sll       $a0, $v1, 3
/* 803348 80242AC8 00641821 */  addu      $v1, $v1, $a0
/* 80334C 80242ACC 000318C0 */  sll       $v1, $v1, 3
/* 803350 80242AD0 3C01800B */  lui       $at, 0x800b
/* 803354 80242AD4 00230821 */  addu      $at, $at, $v1
/* 803358 80242AD8 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 80335C 80242ADC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 803360 80242AE0 8FB10014 */  lw        $s1, 0x14($sp)
/* 803364 80242AE4 8FB00010 */  lw        $s0, 0x10($sp)
/* 803368 80242AE8 03E00008 */  jr        $ra
/* 80336C 80242AEC 27BD0020 */   addiu    $sp, $sp, 0x20
