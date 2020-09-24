.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80147474
/* DDB74 80147474 3C028016 */  lui       $v0, 0x8016
/* DDB78 80147478 24429D50 */  addiu     $v0, $v0, -0x62b0
/* DDB7C 8014747C 00042140 */  sll       $a0, $a0, 5
/* DDB80 80147480 00822021 */  addu      $a0, $a0, $v0
/* DDB84 80147484 8FA70014 */  lw        $a3, 0x14($sp)
/* DDB88 80147488 8FA80018 */  lw        $t0, 0x18($sp)
/* DDB8C 8014748C 9086001C */  lbu       $a2, 0x1c($a0)
/* DDB90 80147490 8FA90024 */  lw        $t1, 0x24($sp)
/* DDB94 80147494 14C00005 */  bnez      $a2, .L801474AC
/* DDB98 80147498 28C20005 */   slti     $v0, $a2, 5
/* DDB9C 8014749C 90820000 */  lbu       $v0, ($a0)
/* DDBA0 801474A0 304200FB */  andi      $v0, $v0, 0xfb
/* DDBA4 801474A4 A0820000 */  sb        $v0, ($a0)
/* DDBA8 801474A8 28C20005 */  slti      $v0, $a2, 5
.L801474AC:
/* DDBAC 801474AC 10400025 */  beqz      $v0, .L80147544
/* DDBB0 801474B0 00000000 */   nop      
/* DDBB4 801474B4 3C038015 */  lui       $v1, 0x8015
/* DDBB8 801474B8 2463F298 */  addiu     $v1, $v1, -0xd68
/* DDBBC 801474BC 3C028015 */  lui       $v0, 0x8015
/* DDBC0 801474C0 00461021 */  addu      $v0, $v0, $a2
/* DDBC4 801474C4 9042F2A0 */  lbu       $v0, -0xd60($v0)
/* DDBC8 801474C8 00C31821 */  addu      $v1, $a2, $v1
/* DDBCC 801474CC ACA20000 */  sw        $v0, ($a1)
/* DDBD0 801474D0 90620000 */  lbu       $v0, ($v1)
/* DDBD4 801474D4 3C018015 */  lui       $at, 0x8015
/* DDBD8 801474D8 D4221240 */  ldc1      $f2, 0x1240($at)
/* DDBDC 801474DC 44820000 */  mtc1      $v0, $f0
/* DDBE0 801474E0 00000000 */  nop       
/* DDBE4 801474E4 46800020 */  cvt.s.w   $f0, $f0
/* DDBE8 801474E8 46000021 */  cvt.d.s   $f0, $f0
/* DDBEC 801474EC 46220002 */  mul.d     $f0, $f0, $f2
/* DDBF0 801474F0 00000000 */  nop       
/* DDBF4 801474F4 46200020 */  cvt.s.d   $f0, $f0
/* DDBF8 801474F8 E4E00000 */  swc1      $f0, ($a3)
/* DDBFC 801474FC 90620000 */  lbu       $v0, ($v1)
/* DDC00 80147500 44820000 */  mtc1      $v0, $f0
/* DDC04 80147504 00000000 */  nop       
/* DDC08 80147508 46800020 */  cvt.s.w   $f0, $f0
/* DDC0C 8014750C 46000021 */  cvt.d.s   $f0, $f0
/* DDC10 80147510 46220002 */  mul.d     $f0, $f0, $f2
/* DDC14 80147514 00000000 */  nop       
/* DDC18 80147518 24030004 */  addiu     $v1, $zero, 4
/* DDC1C 8014751C 00661823 */  subu      $v1, $v1, $a2
/* DDC20 80147520 00031040 */  sll       $v0, $v1, 1
/* DDC24 80147524 00431021 */  addu      $v0, $v0, $v1
/* DDC28 80147528 46200020 */  cvt.s.d   $f0, $f0
/* DDC2C 8014752C E5000000 */  swc1      $f0, ($t0)
/* DDC30 80147530 44820000 */  mtc1      $v0, $f0
/* DDC34 80147534 00000000 */  nop       
/* DDC38 80147538 46800020 */  cvt.s.w   $f0, $f0
/* DDC3C 8014753C 03E00008 */  jr        $ra
/* DDC40 80147540 E5200000 */   swc1     $f0, ($t1)
.L80147544:
/* DDC44 80147544 3C028015 */  lui       $v0, 0x8015
/* DDC48 80147548 9042F2A4 */  lbu       $v0, -0xd5c($v0)
/* DDC4C 8014754C 3C013F80 */  lui       $at, 0x3f80
/* DDC50 80147550 44810000 */  mtc1      $at, $f0
/* DDC54 80147554 ACA20000 */  sw        $v0, ($a1)
/* DDC58 80147558 E4E00000 */  swc1      $f0, ($a3)
/* DDC5C 8014755C E5000000 */  swc1      $f0, ($t0)
/* DDC60 80147560 AD200000 */  sw        $zero, ($t1)
/* DDC64 80147564 90820000 */  lbu       $v0, ($a0)
/* DDC68 80147568 304200F7 */  andi      $v0, $v0, 0xf7
/* DDC6C 8014756C 03E00008 */  jr        $ra
/* DDC70 80147570 A0820000 */   sb       $v0, ($a0)
