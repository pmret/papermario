.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240150_892B70
/* 892B70 80240150 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 892B74 80240154 AFB3001C */  sw        $s3, 0x1c($sp)
/* 892B78 80240158 0080982D */  daddu     $s3, $a0, $zero
/* 892B7C 8024015C AFB00010 */  sw        $s0, 0x10($sp)
/* 892B80 80240160 24100001 */  addiu     $s0, $zero, 1
/* 892B84 80240164 AFB40020 */  sw        $s4, 0x20($sp)
/* 892B88 80240168 2414FFFF */  addiu     $s4, $zero, -1
/* 892B8C 8024016C AFB50024 */  sw        $s5, 0x24($sp)
/* 892B90 80240170 0200A82D */  daddu     $s5, $s0, $zero
/* 892B94 80240174 AFB10014 */  sw        $s1, 0x14($sp)
/* 892B98 80240178 3C118011 */  lui       $s1, %hi(gPlayerData+0x8)
/* 892B9C 8024017C 2631F298 */  addiu     $s1, $s1, %lo(gPlayerData+0x8)
/* 892BA0 80240180 AFBF0028 */  sw        $ra, 0x28($sp)
/* 892BA4 80240184 AFB20018 */  sw        $s2, 0x18($sp)
/* 892BA8 80240188 8E6200B4 */  lw        $v0, 0xb4($s3)
/* 892BAC 8024018C 0280182D */  daddu     $v1, $s4, $zero
/* 892BB0 80240190 AE630084 */  sw        $v1, 0x84($s3)
/* 892BB4 80240194 00021027 */  nor       $v0, $zero, $v0
/* 892BB8 80240198 000217C2 */  srl       $v0, $v0, 0x1f
/* 892BBC 8024019C 00029400 */  sll       $s2, $v0, 0x10
.L802401A0:
/* 892BC0 802401A0 92220014 */  lbu       $v0, 0x14($s1)
/* 892BC4 802401A4 50400008 */  beql      $v0, $zero, .L802401C8
/* 892BC8 802401A8 26100001 */   addiu    $s0, $s0, 1
/* 892BCC 802401AC 0200202D */  daddu     $a0, $s0, $zero
/* 892BD0 802401B0 0C090041 */  jal       func_80240104_892B24
/* 892BD4 802401B4 00122C03 */   sra      $a1, $s2, 0x10
/* 892BD8 802401B8 10540003 */  beq       $v0, $s4, .L802401C8
/* 892BDC 802401BC 26100001 */   addiu    $s0, $s0, 1
/* 892BE0 802401C0 08090075 */  j         .L802401D4
/* 892BE4 802401C4 AE750084 */   sw       $s5, 0x84($s3)
.L802401C8:
/* 892BE8 802401C8 2A02000C */  slti      $v0, $s0, 0xc
/* 892BEC 802401CC 1440FFF4 */  bnez      $v0, .L802401A0
/* 892BF0 802401D0 26310008 */   addiu    $s1, $s1, 8
.L802401D4:
/* 892BF4 802401D4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 892BF8 802401D8 8FB50024 */  lw        $s5, 0x24($sp)
/* 892BFC 802401DC 8FB40020 */  lw        $s4, 0x20($sp)
/* 892C00 802401E0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 892C04 802401E4 8FB20018 */  lw        $s2, 0x18($sp)
/* 892C08 802401E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 892C0C 802401EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 892C10 802401F0 24020002 */  addiu     $v0, $zero, 2
/* 892C14 802401F4 03E00008 */  jr        $ra
/* 892C18 802401F8 27BD0030 */   addiu    $sp, $sp, 0x30
