.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel kill_enemy
/* 019BAC 8003E7AC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 019BB0 8003E7B0 AFB00010 */  sw    $s0, 0x10($sp)
/* 019BB4 8003E7B4 0080802D */  daddu $s0, $a0, $zero
/* 019BB8 8003E7B8 AFBF0020 */  sw    $ra, 0x20($sp)
/* 019BBC 8003E7BC AFB3001C */  sw    $s3, 0x1c($sp)
/* 019BC0 8003E7C0 AFB20018 */  sw    $s2, 0x18($sp)
/* 019BC4 8003E7C4 AFB10014 */  sw    $s1, 0x14($sp)
/* 019BC8 8003E7C8 82020004 */  lb    $v0, 4($s0)
/* 019BCC 8003E7CC 00021080 */  sll   $v0, $v0, 2
/* 019BD0 8003E7D0 3C13800B */  lui   $s3, 0x800b
/* 019BD4 8003E7D4 02629821 */  addu  $s3, $s3, $v0
/* 019BD8 8003E7D8 8E730F38 */  lw    $s3, 0xf38($s3)
/* 019BDC 8003E7DC 8E640000 */  lw    $a0, ($s3)
/* 019BE0 8003E7E0 3C12800B */  lui   $s2, 0x800b
/* 019BE4 8003E7E4 26520F10 */  addiu $s2, $s2, 0xf10
/* 019BE8 8003E7E8 18800009 */  blez  $a0, .L8003E810
/* 019BEC 8003E7EC 0000882D */   daddu $s1, $zero, $zero
/* 019BF0 8003E7F0 0260182D */  daddu $v1, $s3, $zero
.L8003E7F4:
/* 019BF4 8003E7F4 8C620004 */  lw    $v0, 4($v1)
/* 019BF8 8003E7F8 10500005 */  beq   $v0, $s0, .L8003E810
/* 019BFC 8003E7FC 00000000 */   nop   
/* 019C00 8003E800 26310001 */  addiu $s1, $s1, 1
/* 019C04 8003E804 0224102A */  slt   $v0, $s1, $a0
/* 019C08 8003E808 1440FFFA */  bnez  $v0, .L8003E7F4
/* 019C0C 8003E80C 24630004 */   addiu $v1, $v1, 4
.L8003E810:
/* 019C10 8003E810 8E020034 */  lw    $v0, 0x34($s0)
/* 019C14 8003E814 10400003 */  beqz  $v0, .L8003E824
/* 019C18 8003E818 00000000 */   nop   
/* 019C1C 8003E81C 0C0B102B */  jal   kill_script_by_ID
/* 019C20 8003E820 8E04004C */   lw    $a0, 0x4c($s0)
.L8003E824:
/* 019C24 8003E824 8E020038 */  lw    $v0, 0x38($s0)
/* 019C28 8003E828 10400003 */  beqz  $v0, .L8003E838
/* 019C2C 8003E82C 00000000 */   nop   
/* 019C30 8003E830 0C0B102B */  jal   kill_script_by_ID
/* 019C34 8003E834 8E040050 */   lw    $a0, 0x50($s0)
.L8003E838:
/* 019C38 8003E838 8E02003C */  lw    $v0, 0x3c($s0)
/* 019C3C 8003E83C 10400003 */  beqz  $v0, .L8003E84C
/* 019C40 8003E840 00000000 */   nop   
/* 019C44 8003E844 0C0B102B */  jal   kill_script_by_ID
/* 019C48 8003E848 8E040054 */   lw    $a0, 0x54($s0)
.L8003E84C:
/* 019C4C 8003E84C 8E020040 */  lw    $v0, 0x40($s0)
/* 019C50 8003E850 10400003 */  beqz  $v0, .L8003E860
/* 019C54 8003E854 00000000 */   nop   
/* 019C58 8003E858 0C0B102B */  jal   kill_script_by_ID
/* 019C5C 8003E85C 8E040058 */   lw    $a0, 0x58($s0)
.L8003E860:
/* 019C60 8003E860 8E020044 */  lw    $v0, 0x44($s0)
/* 019C64 8003E864 10400003 */  beqz  $v0, .L8003E874
/* 019C68 8003E868 00000000 */   nop   
/* 019C6C 8003E86C 0C0B102B */  jal   kill_script_by_ID
/* 019C70 8003E870 8E04005C */   lw    $a0, 0x5c($s0)
.L8003E874:
/* 019C74 8003E874 8E020048 */  lw    $v0, 0x48($s0)
/* 019C78 8003E878 10400003 */  beqz  $v0, .L8003E888
/* 019C7C 8003E87C 00000000 */   nop   
/* 019C80 8003E880 0C0B102B */  jal   kill_script_by_ID
/* 019C84 8003E884 8E040060 */   lw    $a0, 0x60($s0)
.L8003E888:
/* 019C88 8003E888 86040008 */  lh    $a0, 8($s0)
/* 019C8C 8003E88C AE000020 */  sw    $zero, 0x20($s0)
/* 019C90 8003E890 AE000024 */  sw    $zero, 0x24($s0)
/* 019C94 8003E894 AE000028 */  sw    $zero, 0x28($s0)
/* 019C98 8003E898 AE00002C */  sw    $zero, 0x2c($s0)
/* 019C9C 8003E89C 0C00EABB */  jal   get_npc_unsafe
/* 019CA0 8003E8A0 AE000030 */   sw    $zero, 0x30($s0)
/* 019CA4 8003E8A4 0C00E273 */  jal   free_npc
/* 019CA8 8003E8A8 0040202D */   daddu $a0, $v0, $zero
/* 019CAC 8003E8AC 8E040064 */  lw    $a0, 0x64($s0)
/* 019CB0 8003E8B0 50800004 */  beql  $a0, $zero, .L8003E8C4
/* 019CB4 8003E8B4 0000202D */   daddu $a0, $zero, $zero
/* 019CB8 8003E8B8 0C00AB4B */  jal   heap_free
/* 019CBC 8003E8BC 00000000 */   nop   
/* 019CC0 8003E8C0 0000202D */  daddu $a0, $zero, $zero
.L8003E8C4:
/* 019CC4 8003E8C4 0260182D */  daddu $v1, $s3, $zero
.L8003E8C8:
/* 019CC8 8003E8C8 8C620004 */  lw    $v0, 4($v1)
/* 019CCC 8003E8CC 50500001 */  beql  $v0, $s0, .L8003E8D4
/* 019CD0 8003E8D0 AC600004 */   sw    $zero, 4($v1)
.L8003E8D4:
/* 019CD4 8003E8D4 24840001 */  addiu $a0, $a0, 1
/* 019CD8 8003E8D8 28820010 */  slti  $v0, $a0, 0x10
/* 019CDC 8003E8DC 1440FFFA */  bnez  $v0, .L8003E8C8
/* 019CE0 8003E8E0 24630004 */   addiu $v1, $v1, 4
/* 019CE4 8003E8E4 8E030000 */  lw    $v1, ($s0)
/* 019CE8 8003E8E8 30620004 */  andi  $v0, $v1, 4
/* 019CEC 8003E8EC 1440000E */  bnez  $v0, .L8003E928
/* 019CF0 8003E8F0 30620008 */   andi  $v0, $v1, 8
/* 019CF4 8003E8F4 10400004 */  beqz  $v0, .L8003E908
/* 019CF8 8003E8F8 30620001 */   andi  $v0, $v1, 1
/* 019CFC 8003E8FC 8E42008C */  lw    $v0, 0x8c($s2)
/* 019D00 8003E900 16020009 */  bne   $s0, $v0, .L8003E928
/* 019D04 8003E904 30620001 */   andi  $v0, $v1, 1
.L8003E908:
/* 019D08 8003E908 14400007 */  bnez  $v0, .L8003E928
/* 019D0C 8003E90C 30620010 */   andi  $v0, $v1, 0x10
/* 019D10 8003E910 14400005 */  bnez  $v0, .L8003E928
/* 019D14 8003E914 00000000 */   nop   
/* 019D18 8003E918 86650048 */  lh    $a1, 0x48($s3)
/* 019D1C 8003E91C 82440020 */  lb    $a0, 0x20($s2)
/* 019D20 8003E920 0C00F8B8 */  jal   COPY_set_defeated
/* 019D24 8003E924 00B12821 */   addu  $a1, $a1, $s1
.L8003E928:
/* 019D28 8003E928 0C00AB4B */  jal   heap_free
/* 019D2C 8003E92C 0200202D */   daddu $a0, $s0, $zero
/* 019D30 8003E930 8FBF0020 */  lw    $ra, 0x20($sp)
/* 019D34 8003E934 8FB3001C */  lw    $s3, 0x1c($sp)
/* 019D38 8003E938 8FB20018 */  lw    $s2, 0x18($sp)
/* 019D3C 8003E93C 8FB10014 */  lw    $s1, 0x14($sp)
/* 019D40 8003E940 8FB00010 */  lw    $s0, 0x10($sp)
/* 019D44 8003E944 03E00008 */  jr    $ra
/* 019D48 8003E948 27BD0028 */   addiu $sp, $sp, 0x28

