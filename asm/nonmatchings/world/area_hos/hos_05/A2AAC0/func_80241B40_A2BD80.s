.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B40_A2BD80
/* A2BD80 80241B40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A2BD84 80241B44 AFB00010 */  sw        $s0, 0x10($sp)
/* A2BD88 80241B48 0080802D */  daddu     $s0, $a0, $zero
/* A2BD8C 80241B4C AFB10014 */  sw        $s1, 0x14($sp)
/* A2BD90 80241B50 00A0882D */  daddu     $s1, $a1, $zero
/* A2BD94 80241B54 AFBF0018 */  sw        $ra, 0x18($sp)
/* A2BD98 80241B58 0C0B36B0 */  jal       resolve_npc
/* A2BD9C 80241B5C 24050007 */   addiu    $a1, $zero, 7
/* A2BDA0 80241B60 0200202D */  daddu     $a0, $s0, $zero
/* A2BDA4 80241B64 24050008 */  addiu     $a1, $zero, 8
/* A2BDA8 80241B68 0C0B36B0 */  jal       resolve_npc
/* A2BDAC 80241B6C 0040802D */   daddu    $s0, $v0, $zero
/* A2BDB0 80241B70 12200017 */  beqz      $s1, .L80241BD0
/* A2BDB4 80241B74 0040282D */   daddu    $a1, $v0, $zero
/* A2BDB8 80241B78 3C01C280 */  lui       $at, 0xc280
/* A2BDBC 80241B7C 44810000 */  mtc1      $at, $f0
/* A2BDC0 80241B80 3C014307 */  lui       $at, 0x4307
/* A2BDC4 80241B84 44811000 */  mtc1      $at, $f2
/* A2BDC8 80241B88 3C0142AA */  lui       $at, 0x42aa
/* A2BDCC 80241B8C 44812000 */  mtc1      $at, $f4
/* A2BDD0 80241B90 E6000038 */  swc1      $f0, 0x38($s0)
/* A2BDD4 80241B94 E602003C */  swc1      $f2, 0x3c($s0)
/* A2BDD8 80241B98 E6040040 */  swc1      $f4, 0x40($s0)
/* A2BDDC 80241B9C E4A00038 */  swc1      $f0, 0x38($a1)
/* A2BDE0 80241BA0 E4A2003C */  swc1      $f2, 0x3c($a1)
/* A2BDE4 80241BA4 E4A40040 */  swc1      $f4, 0x40($a1)
/* A2BDE8 80241BA8 C6000038 */  lwc1      $f0, 0x38($s0)
/* A2BDEC 80241BAC E600006C */  swc1      $f0, 0x6c($s0)
/* A2BDF0 80241BB0 C4A00038 */  lwc1      $f0, 0x38($a1)
/* A2BDF4 80241BB4 E4A0006C */  swc1      $f0, 0x6c($a1)
/* A2BDF8 80241BB8 C6000040 */  lwc1      $f0, 0x40($s0)
/* A2BDFC 80241BBC E6000074 */  swc1      $f0, 0x74($s0)
/* A2BE00 80241BC0 C4A00040 */  lwc1      $f0, 0x40($a1)
/* A2BE04 80241BC4 3C018025 */  lui       $at, 0x8025
/* A2BE08 80241BC8 E422F2CC */  swc1      $f2, -0xd34($at)
/* A2BE0C 80241BCC E4A00074 */  swc1      $f0, 0x74($a1)
.L80241BD0:
/* A2BE10 80241BD0 3C048025 */  lui       $a0, 0x8025
/* A2BE14 80241BD4 2484995C */  addiu     $a0, $a0, -0x66a4
/* A2BE18 80241BD8 8C830000 */  lw        $v1, ($a0)
/* A2BE1C 80241BDC 2462FFEC */  addiu     $v0, $v1, -0x14
/* A2BE20 80241BE0 3042001E */  andi      $v0, $v0, 0x1e
/* A2BE24 80241BE4 3C018025 */  lui       $at, 0x8025
/* A2BE28 80241BE8 00220821 */  addu      $at, $at, $v0
/* A2BE2C 80241BEC 84229960 */  lh        $v0, -0x66a0($at)
/* A2BE30 80241BF0 3C013DCC */  lui       $at, 0x3dcc
/* A2BE34 80241BF4 3421CCCD */  ori       $at, $at, 0xcccd
/* A2BE38 80241BF8 44810000 */  mtc1      $at, $f0
/* A2BE3C 80241BFC 44821000 */  mtc1      $v0, $f2
/* A2BE40 80241C00 00000000 */  nop       
/* A2BE44 80241C04 468010A0 */  cvt.s.w   $f2, $f2
/* A2BE48 80241C08 46001082 */  mul.s     $f2, $f2, $f0
/* A2BE4C 80241C0C 00000000 */  nop       
/* A2BE50 80241C10 C600003C */  lwc1      $f0, 0x3c($s0)
/* A2BE54 80241C14 46020000 */  add.s     $f0, $f0, $f2
/* A2BE58 80241C18 E600003C */  swc1      $f0, 0x3c($s0)
/* A2BE5C 80241C1C E4A0003C */  swc1      $f0, 0x3c($a1)
/* A2BE60 80241C20 C600003C */  lwc1      $f0, 0x3c($s0)
/* A2BE64 80241C24 24630001 */  addiu     $v1, $v1, 1
/* A2BE68 80241C28 E6000070 */  swc1      $f0, 0x70($s0)
/* A2BE6C 80241C2C C4A0003C */  lwc1      $f0, 0x3c($a1)
/* A2BE70 80241C30 286207D0 */  slti      $v0, $v1, 0x7d0
/* A2BE74 80241C34 AC830000 */  sw        $v1, ($a0)
/* A2BE78 80241C38 E4A00070 */  swc1      $f0, 0x70($a1)
/* A2BE7C 80241C3C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A2BE80 80241C40 8FB10014 */  lw        $s1, 0x14($sp)
/* A2BE84 80241C44 8FB00010 */  lw        $s0, 0x10($sp)
/* A2BE88 80241C48 38420001 */  xori      $v0, $v0, 1
/* A2BE8C 80241C4C 03E00008 */  jr        $ra
/* A2BE90 80241C50 27BD0020 */   addiu    $sp, $sp, 0x20
