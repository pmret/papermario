.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C4178
/* 3CAF68 E00C4178 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3CAF6C E00C417C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3CAF70 E00C4180 8C850000 */  lw        $a1, ($a0)
/* 3CAF74 E00C4184 8C83000C */  lw        $v1, 0xc($a0)
/* 3CAF78 E00C4188 30A20010 */  andi      $v0, $a1, 0x10
/* 3CAF7C E00C418C 10400005 */  beqz      $v0, .LE00C41A4
/* 3CAF80 E00C4190 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3CAF84 E00C4194 00A21024 */  and       $v0, $a1, $v0
/* 3CAF88 E00C4198 AC820000 */  sw        $v0, ($a0)
/* 3CAF8C E00C419C 24020040 */  addiu     $v0, $zero, 0x40
/* 3CAF90 E00C41A0 AC620010 */  sw        $v0, 0x10($v1)
.LE00C41A4:
/* 3CAF94 E00C41A4 8C650010 */  lw        $a1, 0x10($v1)
/* 3CAF98 E00C41A8 28A203E8 */  slti      $v0, $a1, 0x3e8
/* 3CAF9C E00C41AC 10400002 */  beqz      $v0, .LE00C41B8
/* 3CAFA0 E00C41B0 24A2FFFF */   addiu    $v0, $a1, -1
/* 3CAFA4 E00C41B4 AC620010 */  sw        $v0, 0x10($v1)
.LE00C41B8:
/* 3CAFA8 E00C41B8 8C620014 */  lw        $v0, 0x14($v1)
/* 3CAFAC E00C41BC 8C650010 */  lw        $a1, 0x10($v1)
/* 3CAFB0 E00C41C0 24420001 */  addiu     $v0, $v0, 1
/* 3CAFB4 E00C41C4 04A10005 */  bgez      $a1, .LE00C41DC
/* 3CAFB8 E00C41C8 AC620014 */   sw       $v0, 0x14($v1)
/* 3CAFBC E00C41CC 0C080128 */  jal       func_E02004A0
/* 3CAFC0 E00C41D0 00000000 */   nop
/* 3CAFC4 E00C41D4 080310AE */  j         .LE00C42B8
/* 3CAFC8 E00C41D8 00000000 */   nop
.LE00C41DC:
/* 3CAFCC E00C41DC 00A0202D */  daddu     $a0, $a1, $zero
/* 3CAFD0 E00C41E0 0040282D */  daddu     $a1, $v0, $zero
/* 3CAFD4 E00C41E4 28820040 */  slti      $v0, $a0, 0x40
/* 3CAFD8 E00C41E8 1040000E */  beqz      $v0, .LE00C4224
/* 3CAFDC E00C41EC 28820020 */   slti     $v0, $a0, 0x20
/* 3CAFE0 E00C41F0 C4600030 */  lwc1      $f0, 0x30($v1)
/* 3CAFE4 E00C41F4 3C01E00C */  lui       $at, %hi(D_E00C4A90)
/* 3CAFE8 E00C41F8 D4224A90 */  ldc1      $f2, %lo(D_E00C4A90)($at)
/* 3CAFEC E00C41FC 46000021 */  cvt.d.s   $f0, $f0
/* 3CAFF0 E00C4200 46220001 */  sub.d     $f0, $f0, $f2
/* 3CAFF4 E00C4204 44801000 */  mtc1      $zero, $f2
/* 3CAFF8 E00C4208 46200020 */  cvt.s.d   $f0, $f0
/* 3CAFFC E00C420C 4602003C */  c.lt.s    $f0, $f2
/* 3CB000 E00C4210 00000000 */  nop
/* 3CB004 E00C4214 45000003 */  bc1f      .LE00C4224
/* 3CB008 E00C4218 E4600030 */   swc1     $f0, 0x30($v1)
/* 3CB00C E00C421C E4620030 */  swc1      $f2, 0x30($v1)
/* 3CB010 E00C4220 28820020 */  slti      $v0, $a0, 0x20
.LE00C4224:
/* 3CB014 E00C4224 1040000B */  beqz      $v0, .LE00C4254
/* 3CB018 E00C4228 28820010 */   slti     $v0, $a0, 0x10
/* 3CB01C E00C422C 8C62002C */  lw        $v0, 0x2c($v1)
/* 3CB020 E00C4230 24420080 */  addiu     $v0, $v0, 0x80
/* 3CB024 E00C4234 AC62002C */  sw        $v0, 0x2c($v1)
/* 3CB028 E00C4238 28420100 */  slti      $v0, $v0, 0x100
/* 3CB02C E00C423C 54400004 */  bnel      $v0, $zero, .LE00C4250
/* 3CB030 E00C4240 AC600030 */   sw       $zero, 0x30($v1)
/* 3CB034 E00C4244 240200FF */  addiu     $v0, $zero, 0xff
/* 3CB038 E00C4248 AC62002C */  sw        $v0, 0x2c($v1)
/* 3CB03C E00C424C AC600030 */  sw        $zero, 0x30($v1)
.LE00C4250:
/* 3CB040 E00C4250 28820010 */  slti      $v0, $a0, 0x10
.LE00C4254:
/* 3CB044 E00C4254 10400002 */  beqz      $v0, .LE00C4260
/* 3CB048 E00C4258 00041100 */   sll      $v0, $a0, 4
/* 3CB04C E00C425C AC620024 */  sw        $v0, 0x24($v1)
.LE00C4260:
/* 3CB050 E00C4260 28A20010 */  slti      $v0, $a1, 0x10
/* 3CB054 E00C4264 10400003 */  beqz      $v0, .LE00C4274
/* 3CB058 E00C4268 00051100 */   sll      $v0, $a1, 4
/* 3CB05C E00C426C 2442000F */  addiu     $v0, $v0, 0xf
/* 3CB060 E00C4270 AC620024 */  sw        $v0, 0x24($v1)
.LE00C4274:
/* 3CB064 E00C4274 0000202D */  daddu     $a0, $zero, $zero
/* 3CB068 E00C4278 240500FF */  addiu     $a1, $zero, 0xff
.LE00C427C:
/* 3CB06C E00C427C 8C62014C */  lw        $v0, 0x14c($v1)
/* 3CB070 E00C4280 10400003 */  beqz      $v0, .LE00C4290
/* 3CB074 E00C4284 2442FFFF */   addiu    $v0, $v0, -1
/* 3CB078 E00C4288 14400007 */  bnez      $v0, .LE00C42A8
/* 3CB07C E00C428C AC62014C */   sw       $v0, 0x14c($v1)
.LE00C4290:
/* 3CB080 E00C4290 8C620124 */  lw        $v0, 0x124($v1)
/* 3CB084 E00C4294 24420008 */  addiu     $v0, $v0, 8
/* 3CB088 E00C4298 AC620124 */  sw        $v0, 0x124($v1)
/* 3CB08C E00C429C 28420100 */  slti      $v0, $v0, 0x100
/* 3CB090 E00C42A0 50400001 */  beql      $v0, $zero, .LE00C42A8
/* 3CB094 E00C42A4 AC650124 */   sw       $a1, 0x124($v1)
.LE00C42A8:
/* 3CB098 E00C42A8 24840001 */  addiu     $a0, $a0, 1
/* 3CB09C E00C42AC 2882000A */  slti      $v0, $a0, 0xa
/* 3CB0A0 E00C42B0 1440FFF2 */  bnez      $v0, .LE00C427C
/* 3CB0A4 E00C42B4 24630004 */   addiu    $v1, $v1, 4
.LE00C42B8:
/* 3CB0A8 E00C42B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3CB0AC E00C42BC 03E00008 */  jr        $ra
/* 3CB0B0 E00C42C0 27BD0018 */   addiu    $sp, $sp, 0x18
