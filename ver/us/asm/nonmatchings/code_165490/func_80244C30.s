.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244C30
/* 165490 80244C30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 165494 80244C34 AFB20020 */  sw        $s2, 0x20($sp)
/* 165498 80244C38 00A0902D */  daddu     $s2, $a1, $zero
/* 16549C 80244C3C AFBF0028 */  sw        $ra, 0x28($sp)
/* 1654A0 80244C40 AFB30024 */  sw        $s3, 0x24($sp)
/* 1654A4 80244C44 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1654A8 80244C48 AFB00018 */  sw        $s0, 0x18($sp)
/* 1654AC 80244C4C 80830004 */  lb        $v1, 4($a0)
/* 1654B0 80244C50 2C620005 */  sltiu     $v0, $v1, 5
/* 1654B4 80244C54 10400013 */  beqz      $v0, L80244CA4_165504
/* 1654B8 80244C58 00C0982D */   daddu    $s3, $a2, $zero
/* 1654BC 80244C5C 00031080 */  sll       $v0, $v1, 2
/* 1654C0 80244C60 3C018025 */  lui       $at, %hi(jtbl_8024BF70)
/* 1654C4 80244C64 00220821 */  addu      $at, $at, $v0
/* 1654C8 80244C68 8C22BF70 */  lw        $v0, %lo(jtbl_8024BF70)($at)
/* 1654CC 80244C6C 00400008 */  jr        $v0
/* 1654D0 80244C70 00000000 */   nop
glabel L80244C74_1654D4
/* 1654D4 80244C74 24040001 */  addiu     $a0, $zero, 1
/* 1654D8 80244C78 0809132B */  j         .L80244CAC
/* 1654DC 80244C7C 24110009 */   addiu    $s1, $zero, 9
glabel L80244C80_1654E0
/* 1654E0 80244C80 24040002 */  addiu     $a0, $zero, 2
/* 1654E4 80244C84 0809132B */  j         .L80244CAC
/* 1654E8 80244C88 24110008 */   addiu    $s1, $zero, 8
glabel L80244C8C_1654EC
/* 1654EC 80244C8C 24040004 */  addiu     $a0, $zero, 4
/* 1654F0 80244C90 0809132B */  j         .L80244CAC
/* 1654F4 80244C94 24110019 */   addiu    $s1, $zero, 0x19
glabel L80244C98_1654F8
/* 1654F8 80244C98 24040005 */  addiu     $a0, $zero, 5
/* 1654FC 80244C9C 0809132B */  j         .L80244CAC
/* 165500 80244CA0 24110010 */   addiu    $s1, $zero, 0x10
glabel L80244CA4_165504
/* 165504 80244CA4 24040003 */  addiu     $a0, $zero, 3
/* 165508 80244CA8 2411000A */  addiu     $s1, $zero, 0xa
.L80244CAC:
/* 16550C 80244CAC 0C0926A9 */  jal       func_80249AA4
/* 165510 80244CB0 24100004 */   addiu    $s0, $zero, 4
/* 165514 80244CB4 0040202D */  daddu     $a0, $v0, $zero
/* 165518 80244CB8 02512821 */  addu      $a1, $s2, $s1
/* 16551C 80244CBC 02703021 */  addu      $a2, $s3, $s0
/* 165520 80244CC0 240700FF */  addiu     $a3, $zero, 0xff
/* 165524 80244CC4 AFA00010 */  sw        $zero, 0x10($sp)
/* 165528 80244CC8 0C09265F */  jal       func_8024997C
/* 16552C 80244CCC AFA00014 */   sw       $zero, 0x14($sp)
/* 165530 80244CD0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 165534 80244CD4 8FB30024 */  lw        $s3, 0x24($sp)
/* 165538 80244CD8 8FB20020 */  lw        $s2, 0x20($sp)
/* 16553C 80244CDC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 165540 80244CE0 8FB00018 */  lw        $s0, 0x18($sp)
/* 165544 80244CE4 03E00008 */  jr        $ra
/* 165548 80244CE8 27BD0030 */   addiu    $sp, $sp, 0x30
