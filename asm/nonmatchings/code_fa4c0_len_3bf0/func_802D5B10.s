.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802D5B10
/* 0FA4C0 802D5B10 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0FA4C4 802D5B14 27A40010 */  addiu $a0, $sp, 0x10
/* 0FA4C8 802D5B18 27A50014 */  addiu $a1, $sp, 0x14
/* 0FA4CC 802D5B1C AFBF0038 */  sw    $ra, 0x38($sp)
/* 0FA4D0 802D5B20 AFB70034 */  sw    $s7, 0x34($sp)
/* 0FA4D4 802D5B24 AFB60030 */  sw    $s6, 0x30($sp)
/* 0FA4D8 802D5B28 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0FA4DC 802D5B2C AFB40028 */  sw    $s4, 0x28($sp)
/* 0FA4E0 802D5B30 AFB30024 */  sw    $s3, 0x24($sp)
/* 0FA4E4 802D5B34 AFB20020 */  sw    $s2, 0x20($sp)
/* 0FA4E8 802D5B38 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FA4EC 802D5B3C 0C015823 */  jal   func_8005608C
/* 0FA4F0 802D5B40 AFB00018 */   sw    $s0, 0x18($sp)
/* 0FA4F4 802D5B44 8FA20014 */  lw    $v0, 0x14($sp)
/* 0FA4F8 802D5B48 10400036 */  beqz  $v0, .L802D5C24
/* 0FA4FC 802D5B4C 0000982D */   daddu $s3, $zero, $zero
/* 0FA500 802D5B50 3C1700FF */  lui   $s7, 0xff
/* 0FA504 802D5B54 2416FFFF */  addiu $s6, $zero, -1
/* 0FA508 802D5B58 3C15802E */  lui   $s5, 0x802e
/* 0FA50C 802D5B5C 26B5B7D8 */  addiu $s5, $s5, -0x4828
/* 0FA510 802D5B60 3C14802E */  lui   $s4, 0x802e
/* 0FA514 802D5B64 2694B800 */  addiu $s4, $s4, -0x4800
.L802D5B68:
/* 0FA518 802D5B68 8FA20010 */  lw    $v0, 0x10($sp)
/* 0FA51C 802D5B6C 8C430000 */  lw    $v1, ($v0)
/* 0FA520 802D5B70 3C04802E */  lui   $a0, 0x802e
/* 0FA524 802D5B74 8C84B7D0 */  lw    $a0, -0x4830($a0)
/* 0FA528 802D5B78 00771024 */  and   $v0, $v1, $s7
/* 0FA52C 802D5B7C 00022C02 */  srl   $a1, $v0, 0x10
/* 0FA530 802D5B80 8C820000 */  lw    $v0, ($a0)
/* 0FA534 802D5B84 10560009 */  beq   $v0, $s6, .L802D5BAC
/* 0FA538 802D5B88 306300FF */   andi  $v1, $v1, 0xff
/* 0FA53C 802D5B8C 2406FFFF */  addiu $a2, $zero, -1
/* 0FA540 802D5B90 8C820000 */  lw    $v0, ($a0)
.L802D5B94:
/* 0FA544 802D5B94 10450005 */  beq   $v0, $a1, .L802D5BAC
/* 0FA548 802D5B98 00000000 */   nop   
/* 0FA54C 802D5B9C 24840014 */  addiu $a0, $a0, 0x14
/* 0FA550 802D5BA0 8C820000 */  lw    $v0, ($a0)
/* 0FA554 802D5BA4 1446FFFB */  bne   $v0, $a2, .L802D5B94
/* 0FA558 802D5BA8 00000000 */   nop   
.L802D5BAC:
/* 0FA55C 802D5BAC 50800017 */  beql  $a0, $zero, .L802D5C0C
/* 0FA560 802D5BB0 26730001 */   addiu $s3, $s3, 1
/* 0FA564 802D5BB4 00031080 */  sll   $v0, $v1, 2
/* 0FA568 802D5BB8 00821021 */  addu  $v0, $a0, $v0
/* 0FA56C 802D5BBC 00058880 */  sll   $s1, $a1, 2
/* 0FA570 802D5BC0 02359021 */  addu  $s2, $s1, $s5
/* 0FA574 802D5BC4 8E430000 */  lw    $v1, ($s2)
/* 0FA578 802D5BC8 8C500004 */  lw    $s0, 4($v0)
/* 0FA57C 802D5BCC 10600004 */  beqz  $v1, .L802D5BE0
/* 0FA580 802D5BD0 02341021 */   addu  $v0, $s1, $s4
/* 0FA584 802D5BD4 8C440000 */  lw    $a0, ($v0)
/* 0FA588 802D5BD8 0C0B102B */  jal   kill_script_by_ID
/* 0FA58C 802D5BDC 00000000 */   nop   
.L802D5BE0:
/* 0FA590 802D5BE0 5200000A */  beql  $s0, $zero, .L802D5C0C
/* 0FA594 802D5BE4 26730001 */   addiu $s3, $s3, 1
/* 0FA598 802D5BE8 0200202D */  daddu $a0, $s0, $zero
/* 0FA59C 802D5BEC 24050001 */  addiu $a1, $zero, 1
/* 0FA5A0 802D5BF0 0C0B0CF8 */  jal   start_script
/* 0FA5A4 802D5BF4 0000302D */   daddu $a2, $zero, $zero
/* 0FA5A8 802D5BF8 AE420000 */  sw    $v0, ($s2)
/* 0FA5AC 802D5BFC 8C430144 */  lw    $v1, 0x144($v0)
/* 0FA5B0 802D5C00 02341021 */  addu  $v0, $s1, $s4
/* 0FA5B4 802D5C04 AC430000 */  sw    $v1, ($v0)
/* 0FA5B8 802D5C08 26730001 */  addiu $s3, $s3, 1
.L802D5C0C:
/* 0FA5BC 802D5C0C 8FA20010 */  lw    $v0, 0x10($sp)
/* 0FA5C0 802D5C10 8FA30014 */  lw    $v1, 0x14($sp)
/* 0FA5C4 802D5C14 24420004 */  addiu $v0, $v0, 4
/* 0FA5C8 802D5C18 0263182B */  sltu  $v1, $s3, $v1
/* 0FA5CC 802D5C1C 1460FFD2 */  bnez  $v1, .L802D5B68
/* 0FA5D0 802D5C20 AFA20010 */   sw    $v0, 0x10($sp)
.L802D5C24:
/* 0FA5D4 802D5C24 0C01582A */  jal   func_800560A8
/* 0FA5D8 802D5C28 00000000 */   nop   
/* 0FA5DC 802D5C2C 3C04802E */  lui   $a0, 0x802e
/* 0FA5E0 802D5C30 24849D30 */  addiu $a0, $a0, -0x62d0
/* 0FA5E4 802D5C34 8C830000 */  lw    $v1, ($a0)
/* 0FA5E8 802D5C38 24630001 */  addiu $v1, $v1, 1
/* 0FA5EC 802D5C3C AC830000 */  sw    $v1, ($a0)
/* 0FA5F0 802D5C40 8FBF0038 */  lw    $ra, 0x38($sp)
/* 0FA5F4 802D5C44 8FB70034 */  lw    $s7, 0x34($sp)
/* 0FA5F8 802D5C48 8FB60030 */  lw    $s6, 0x30($sp)
/* 0FA5FC 802D5C4C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0FA600 802D5C50 8FB40028 */  lw    $s4, 0x28($sp)
/* 0FA604 802D5C54 8FB30024 */  lw    $s3, 0x24($sp)
/* 0FA608 802D5C58 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FA60C 802D5C5C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FA610 802D5C60 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FA614 802D5C64 0000102D */  daddu $v0, $zero, $zero
/* 0FA618 802D5C68 03E00008 */  jr    $ra
/* 0FA61C 802D5C6C 27BD0040 */   addiu $sp, $sp, 0x40

glabel func_802D5C70
/* 0FA620 802D5C70 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA624 802D5C74 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA628 802D5C78 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA62C 802D5C7C 0C0B1EAF */  jal   get_variable
/* 0FA630 802D5C80 8C450000 */   lw    $a1, ($v0)
/* 0FA634 802D5C84 0000282D */  daddu $a1, $zero, $zero
/* 0FA638 802D5C88 3C04802E */  lui   $a0, 0x802e
/* 0FA63C 802D5C8C 2484B800 */  addiu $a0, $a0, -0x4800
/* 0FA640 802D5C90 3C03802E */  lui   $v1, 0x802e
/* 0FA644 802D5C94 2463B7D8 */  addiu $v1, $v1, -0x4828
/* 0FA648 802D5C98 3C01802E */  lui   $at, 0x802e
/* 0FA64C 802D5C9C AC22B7D0 */  sw    $v0, -0x4830($at)
.L802D5CA0:
/* 0FA650 802D5CA0 AC600000 */  sw    $zero, ($v1)
/* 0FA654 802D5CA4 AC800000 */  sw    $zero, ($a0)
/* 0FA658 802D5CA8 24840004 */  addiu $a0, $a0, 4
/* 0FA65C 802D5CAC 24A50001 */  addiu $a1, $a1, 1
/* 0FA660 802D5CB0 28A2000A */  slti  $v0, $a1, 0xa
/* 0FA664 802D5CB4 1440FFFA */  bnez  $v0, .L802D5CA0
/* 0FA668 802D5CB8 24630004 */   addiu $v1, $v1, 4
/* 0FA66C 802D5CBC 3C04802E */  lui   $a0, 0x802e
/* 0FA670 802D5CC0 24849D34 */  addiu $a0, $a0, -0x62cc
/* 0FA674 802D5CC4 24050001 */  addiu $a1, $zero, 1
/* 0FA678 802D5CC8 0C0B0CF8 */  jal   start_script
/* 0FA67C 802D5CCC 0000302D */   daddu $a2, $zero, $zero
/* 0FA680 802D5CD0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA684 802D5CD4 24020002 */  addiu $v0, $zero, 2
/* 0FA688 802D5CD8 03E00008 */  jr    $ra
/* 0FA68C 802D5CDC 27BD0018 */   addiu $sp, $sp, 0x18

