.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_read_flash
/* 6C68 8002B868 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 6C6C 8002B86C AFB40060 */  sw        $s4, 0x60($sp)
/* 6C70 8002B870 0080A02D */  daddu     $s4, $a0, $zero
/* 6C74 8002B874 AFB10054 */  sw        $s1, 0x54($sp)
/* 6C78 8002B878 00C0882D */  daddu     $s1, $a2, $zero
/* 6C7C 8002B87C AFB20058 */  sw        $s2, 0x58($sp)
/* 6C80 8002B880 00A0902D */  daddu     $s2, $a1, $zero
/* 6C84 8002B884 0240202D */  daddu     $a0, $s2, $zero
/* 6C88 8002B888 0220282D */  daddu     $a1, $s1, $zero
/* 6C8C 8002B88C AFBF006C */  sw        $ra, 0x6c($sp)
/* 6C90 8002B890 AFB60068 */  sw        $s6, 0x68($sp)
/* 6C94 8002B894 AFB50064 */  sw        $s5, 0x64($sp)
/* 6C98 8002B898 AFB3005C */  sw        $s3, 0x5c($sp)
/* 6C9C 8002B89C 0C0185C8 */  jal       osInvalDCache
/* 6CA0 8002B8A0 AFB00050 */   sw       $s0, 0x50($sp)
/* 6CA4 8002B8A4 27B00030 */  addiu     $s0, $sp, 0x30
/* 6CA8 8002B8A8 0200202D */  daddu     $a0, $s0, $zero
/* 6CAC 8002B8AC 27A50048 */  addiu     $a1, $sp, 0x48
/* 6CB0 8002B8B0 0C019560 */  jal       osCreateMesgQueue
/* 6CB4 8002B8B4 24060001 */   addiu    $a2, $zero, 1
/* 6CB8 8002B8B8 12200018 */  beqz      $s1, .L8002B91C
/* 6CBC 8002B8BC 0000982D */   daddu    $s3, $zero, $zero
/* 6CC0 8002B8C0 0014A9C0 */  sll       $s5, $s4, 7
/* 6CC4 8002B8C4 24160001 */  addiu     $s6, $zero, 1
/* 6CC8 8002B8C8 0200A02D */  daddu     $s4, $s0, $zero
.L8002B8CC:
/* 6CCC 8002B8CC 2E220081 */  sltiu     $v0, $s1, 0x81
/* 6CD0 8002B8D0 14400002 */  bnez      $v0, .L8002B8DC
/* 6CD4 8002B8D4 0220802D */   daddu    $s0, $s1, $zero
/* 6CD8 8002B8D8 24100080 */  addiu     $s0, $zero, 0x80
.L8002B8DC:
/* 6CDC 8002B8DC 27A40018 */  addiu     $a0, $sp, 0x18
/* 6CE0 8002B8E0 0000282D */  daddu     $a1, $zero, $zero
/* 6CE4 8002B8E4 3266FFFF */  andi      $a2, $s3, 0xffff
/* 6CE8 8002B8E8 02A63021 */  addu      $a2, $s5, $a2
/* 6CEC 8002B8EC 0240382D */  daddu     $a3, $s2, $zero
/* 6CF0 8002B8F0 AFB60010 */  sw        $s6, 0x10($sp)
/* 6CF4 8002B8F4 0C01BDD7 */  jal       osFlashReadArray
/* 6CF8 8002B8F8 AFB40014 */   sw       $s4, 0x14($sp)
/* 6CFC 8002B8FC 0280202D */  daddu     $a0, $s4, $zero
/* 6D00 8002B900 0000282D */  daddu     $a1, $zero, $zero
/* 6D04 8002B904 0C0195BC */  jal       osRecvMesg
/* 6D08 8002B908 24060001 */   addiu    $a2, $zero, 1
/* 6D0C 8002B90C 26730001 */  addiu     $s3, $s3, 1
/* 6D10 8002B910 02308823 */  subu      $s1, $s1, $s0
/* 6D14 8002B914 1620FFED */  bnez      $s1, .L8002B8CC
/* 6D18 8002B918 02509021 */   addu     $s2, $s2, $s0
.L8002B91C:
/* 6D1C 8002B91C 8FBF006C */  lw        $ra, 0x6c($sp)
/* 6D20 8002B920 8FB60068 */  lw        $s6, 0x68($sp)
/* 6D24 8002B924 8FB50064 */  lw        $s5, 0x64($sp)
/* 6D28 8002B928 8FB40060 */  lw        $s4, 0x60($sp)
/* 6D2C 8002B92C 8FB3005C */  lw        $s3, 0x5c($sp)
/* 6D30 8002B930 8FB20058 */  lw        $s2, 0x58($sp)
/* 6D34 8002B934 8FB10054 */  lw        $s1, 0x54($sp)
/* 6D38 8002B938 8FB00050 */  lw        $s0, 0x50($sp)
/* 6D3C 8002B93C 24020001 */  addiu     $v0, $zero, 1
/* 6D40 8002B940 03E00008 */  jr        $ra
/* 6D44 8002B944 27BD0070 */   addiu    $sp, $sp, 0x70
