.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066110
/* 41510 80066110 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 41514 80066114 AFB00010 */  sw        $s0, 0x10($sp)
/* 41518 80066118 00808021 */  addu      $s0, $a0, $zero
/* 4151C 8006611C AFBF0018 */  sw        $ra, 0x18($sp)
/* 41520 80066120 0C01ACD0 */  jal       func_8006B340
/* 41524 80066124 AFB10014 */   sw       $s1, 0x14($sp)
/* 41528 80066128 24030004 */  addiu     $v1, $zero, 4
/* 4152C 8006612C 12000002 */  beqz      $s0, .L80066138
/* 41530 80066130 00408821 */   addu     $s1, $v0, $zero
/* 41534 80066134 96030010 */  lhu       $v1, 0x10($s0)
.L80066138:
/* 41538 80066138 3063FFFF */  andi      $v1, $v1, 0xffff
/* 4153C 8006613C 24020004 */  addiu     $v0, $zero, 4
/* 41540 80066140 1062000C */  beq       $v1, $v0, .L80066174
/* 41544 80066144 28620005 */   slti     $v0, $v1, 5
/* 41548 80066148 10400005 */  beqz      $v0, .L80066160
/* 4154C 8006614C 24020002 */   addiu    $v0, $zero, 2
/* 41550 80066150 10620010 */  beq       $v1, $v0, .L80066194
/* 41554 80066154 00000000 */   nop
/* 41558 80066158 0801986A */  j         .L800661A8
/* 4155C 8006615C 00000000 */   nop
.L80066160:
/* 41560 80066160 24020008 */  addiu     $v0, $zero, 8
/* 41564 80066164 1062000B */  beq       $v1, $v0, .L80066194
/* 41568 80066168 00000000 */   nop
/* 4156C 8006616C 0801986A */  j         .L800661A8
/* 41570 80066170 00000000 */   nop
.L80066174:
/* 41574 80066174 3C038009 */  lui       $v1, %hi(D_80094640)
/* 41578 80066178 8C634640 */  lw        $v1, %lo(D_80094640)($v1)
/* 4157C 8006617C 00002021 */  addu      $a0, $zero, $zero
/* 41580 80066180 24020001 */  addiu     $v0, $zero, 1
/* 41584 80066184 0C01AC13 */  jal       func_8006B04C
/* 41588 80066188 A4620010 */   sh       $v0, 0x10($v1)
/* 4158C 8006618C 0801986A */  j         .L800661A8
/* 41590 80066190 00000000 */   nop
.L80066194:
/* 41594 80066194 8E040008 */  lw        $a0, 8($s0)
/* 41598 80066198 24020001 */  addiu     $v0, $zero, 1
/* 4159C 8006619C 02002821 */  addu      $a1, $s0, $zero
/* 415A0 800661A0 0C019874 */  jal       func_800661D0
/* 415A4 800661A4 A6020010 */   sh       $v0, 0x10($s0)
.L800661A8:
/* 415A8 800661A8 0C01ACEC */  jal       func_8006B3B0
/* 415AC 800661AC 02202021 */   addu     $a0, $s1, $zero
/* 415B0 800661B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 415B4 800661B4 8FB10014 */  lw        $s1, 0x14($sp)
/* 415B8 800661B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 415BC 800661BC 03E00008 */  jr        $ra
/* 415C0 800661C0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 415C4 800661C4 00000000 */  nop
/* 415C8 800661C8 00000000 */  nop
/* 415CC 800661CC 00000000 */  nop
