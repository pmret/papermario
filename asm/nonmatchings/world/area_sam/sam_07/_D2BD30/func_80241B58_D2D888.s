.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B58_D2D888
/* D2D888 80241B58 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D2D88C 80241B5C AFB10034 */  sw        $s1, 0x34($sp)
/* D2D890 80241B60 0080882D */  daddu     $s1, $a0, $zero
/* D2D894 80241B64 AFBF0038 */  sw        $ra, 0x38($sp)
/* D2D898 80241B68 AFB00030 */  sw        $s0, 0x30($sp)
/* D2D89C 80241B6C 8E300148 */  lw        $s0, 0x148($s1)
/* D2D8A0 80241B70 0C00EABB */  jal       get_npc_unsafe
/* D2D8A4 80241B74 86040008 */   lh       $a0, 8($s0)
/* D2D8A8 80241B78 0040282D */  daddu     $a1, $v0, $zero
/* D2D8AC 80241B7C 94A2008E */  lhu       $v0, 0x8e($a1)
/* D2D8B0 80241B80 24420001 */  addiu     $v0, $v0, 1
/* D2D8B4 80241B84 A4A2008E */  sh        $v0, 0x8e($a1)
/* D2D8B8 80241B88 00021400 */  sll       $v0, $v0, 0x10
/* D2D8BC 80241B8C 8E0300A0 */  lw        $v1, 0xa0($s0)
/* D2D8C0 80241B90 00021403 */  sra       $v0, $v0, 0x10
/* D2D8C4 80241B94 14430004 */  bne       $v0, $v1, .L80241BA8
/* D2D8C8 80241B98 00000000 */   nop      
/* D2D8CC 80241B9C 8E0200CC */  lw        $v0, 0xcc($s0)
/* D2D8D0 80241BA0 8C42002C */  lw        $v0, 0x2c($v0)
/* D2D8D4 80241BA4 ACA20028 */  sw        $v0, 0x28($a1)
.L80241BA8:
/* D2D8D8 80241BA8 84A3008E */  lh        $v1, 0x8e($a1)
/* D2D8DC 80241BAC 8E0200A4 */  lw        $v0, 0xa4($s0)
/* D2D8E0 80241BB0 14620002 */  bne       $v1, $v0, .L80241BBC
/* D2D8E4 80241BB4 24020003 */   addiu    $v0, $zero, 3
/* D2D8E8 80241BB8 AE02006C */  sw        $v0, 0x6c($s0)
.L80241BBC:
/* D2D8EC 80241BBC 84A2008E */  lh        $v0, 0x8e($a1)
/* D2D8F0 80241BC0 8E03009C */  lw        $v1, 0x9c($s0)
/* D2D8F4 80241BC4 0043102A */  slt       $v0, $v0, $v1
/* D2D8F8 80241BC8 1440001E */  bnez      $v0, .L80241C44
/* D2D8FC 80241BCC 24020004 */   addiu    $v0, $zero, 4
/* D2D900 80241BD0 AE02006C */  sw        $v0, 0x6c($s0)
/* D2D904 80241BD4 24020008 */  addiu     $v0, $zero, 8
/* D2D908 80241BD8 24040003 */  addiu     $a0, $zero, 3
/* D2D90C 80241BDC A4A2008E */  sh        $v0, 0x8e($a1)
/* D2D910 80241BE0 8E0200CC */  lw        $v0, 0xcc($s0)
/* D2D914 80241BE4 84A300A8 */  lh        $v1, 0xa8($a1)
/* D2D918 80241BE8 3C013F80 */  lui       $at, 0x3f80
/* D2D91C 80241BEC 44810000 */  mtc1      $at, $f0
/* D2D920 80241BF0 3C014000 */  lui       $at, 0x4000
/* D2D924 80241BF4 44811000 */  mtc1      $at, $f2
/* D2D928 80241BF8 3C01C1A0 */  lui       $at, 0xc1a0
/* D2D92C 80241BFC 44812000 */  mtc1      $at, $f4
/* D2D930 80241C00 44833000 */  mtc1      $v1, $f6
/* D2D934 80241C04 00000000 */  nop       
/* D2D938 80241C08 468031A0 */  cvt.s.w   $f6, $f6
/* D2D93C 80241C0C 8C420000 */  lw        $v0, ($v0)
/* D2D940 80241C10 44073000 */  mfc1      $a3, $f6
/* D2D944 80241C14 0000302D */  daddu     $a2, $zero, $zero
/* D2D948 80241C18 ACA20028 */  sw        $v0, 0x28($a1)
/* D2D94C 80241C1C 2402000A */  addiu     $v0, $zero, 0xa
/* D2D950 80241C20 AFA2001C */  sw        $v0, 0x1c($sp)
/* D2D954 80241C24 27A20028 */  addiu     $v0, $sp, 0x28
/* D2D958 80241C28 E7A00010 */  swc1      $f0, 0x10($sp)
/* D2D95C 80241C2C E7A20014 */  swc1      $f2, 0x14($sp)
/* D2D960 80241C30 E7A40018 */  swc1      $f4, 0x18($sp)
/* D2D964 80241C34 0C01BFA4 */  jal       fx_emote
/* D2D968 80241C38 AFA20020 */   sw       $v0, 0x20($sp)
/* D2D96C 80241C3C 2402000D */  addiu     $v0, $zero, 0xd
/* D2D970 80241C40 AE220070 */  sw        $v0, 0x70($s1)
.L80241C44:
/* D2D974 80241C44 8FBF0038 */  lw        $ra, 0x38($sp)
/* D2D978 80241C48 8FB10034 */  lw        $s1, 0x34($sp)
/* D2D97C 80241C4C 8FB00030 */  lw        $s0, 0x30($sp)
/* D2D980 80241C50 03E00008 */  jr        $ra
/* D2D984 80241C54 27BD0040 */   addiu    $sp, $sp, 0x40
