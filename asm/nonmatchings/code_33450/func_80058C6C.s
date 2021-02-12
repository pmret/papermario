.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80098938
.double 65535.0

.section .text

glabel func_80058C6C
/* 3406C 80058C6C 8FA20010 */  lw        $v0, 0x10($sp)
/* 34070 80058C70 1440000B */  bnez      $v0, .L80058CA0
/* 34074 80058C74 8FA50014 */   lw       $a1, 0x14($sp)
/* 34078 80058C78 462E603E */  c.le.d    $f12, $f14
/* 3407C 80058C7C 00000000 */  nop
/* 34080 80058C80 45020005 */  bc1fl     .L80058C98
/* 34084 80058C84 A4A00000 */   sh       $zero, ($a1)
/* 34088 80058C88 3402FFFF */  ori       $v0, $zero, 0xffff
/* 3408C 80058C8C A4A20000 */  sh        $v0, ($a1)
/* 34090 80058C90 03E00008 */  jr        $ra
/* 34094 80058C94 24027FFF */   addiu    $v0, $zero, 0x7fff
.L80058C98:
/* 34098 80058C98 03E00008 */  jr        $ra
/* 3409C 80058C9C 0000102D */   daddu    $v0, $zero, $zero
.L80058CA0:
/* 340A0 80058CA0 3C013FF0 */  lui       $at, 0x3ff0
/* 340A4 80058CA4 44812800 */  mtc1      $at, $f5
/* 340A8 80058CA8 44802000 */  mtc1      $zero, $f4
/* 340AC 80058CAC 44820000 */  mtc1      $v0, $f0
/* 340B0 80058CB0 00000000 */  nop
/* 340B4 80058CB4 46800021 */  cvt.d.w   $f0, $f0
/* 340B8 80058CB8 4624703C */  c.lt.d    $f14, $f4
/* 340BC 80058CBC 00000000 */  nop
/* 340C0 80058CC0 45000002 */  bc1f      .L80058CCC
/* 340C4 80058CC4 46202083 */   div.d    $f2, $f4, $f0
/* 340C8 80058CC8 46202386 */  mov.d     $f14, $f4
.L80058CCC:
/* 340CC 80058CCC 44800000 */  mtc1      $zero, $f0
/* 340D0 80058CD0 44800800 */  mtc1      $zero, $f1
/* 340D4 80058CD4 00000000 */  nop
/* 340D8 80058CD8 4620603E */  c.le.d    $f12, $f0
/* 340DC 80058CDC 00000000 */  nop
/* 340E0 80058CE0 45030001 */  bc1tl     .L80058CE8
/* 340E4 80058CE4 46202306 */   mov.d    $f12, $f4
.L80058CE8:
/* 340E8 80058CE8 462C7001 */  sub.d     $f0, $f14, $f12
/* 340EC 80058CEC 46220002 */  mul.d     $f0, $f0, $f2
/* 340F0 80058CF0 00000000 */  nop
/* 340F4 80058CF4 3C014020 */  lui       $at, 0x4020
/* 340F8 80058CF8 44811800 */  mtc1      $at, $f3
/* 340FC 80058CFC 44801000 */  mtc1      $zero, $f2
/* 34100 80058D00 00000000 */  nop
/* 34104 80058D04 46220002 */  mul.d     $f0, $f0, $f2
/* 34108 80058D08 00000000 */  nop
/* 3410C 80058D0C 4620018D */  trunc.w.d $f6, $f0
/* 34110 80058D10 44033000 */  mfc1      $v1, $f6
/* 34114 80058D14 00000000 */  nop
/* 34118 80058D18 00031400 */  sll       $v0, $v1, 0x10
/* 3411C 80058D1C 00021403 */  sra       $v0, $v0, 0x10
/* 34120 80058D20 44821000 */  mtc1      $v0, $f2
/* 34124 80058D24 00000000 */  nop
/* 34128 80058D28 468010A1 */  cvt.d.w   $f2, $f2
/* 3412C 80058D2C 46220001 */  sub.d     $f0, $f0, $f2
/* 34130 80058D30 46240000 */  add.d     $f0, $f0, $f4
/* 34134 80058D34 4620018D */  trunc.w.d $f6, $f0
/* 34138 80058D38 44043000 */  mfc1      $a0, $f6
/* 3413C 80058D3C 00000000 */  nop
/* 34140 80058D40 00041400 */  sll       $v0, $a0, 0x10
/* 34144 80058D44 00021403 */  sra       $v0, $v0, 0x10
/* 34148 80058D48 44821000 */  mtc1      $v0, $f2
/* 3414C 80058D4C 00000000 */  nop
/* 34150 80058D50 468010A1 */  cvt.d.w   $f2, $f2
/* 34154 80058D54 46220001 */  sub.d     $f0, $f0, $f2
/* 34158 80058D58 3C01800A */  lui       $at, %hi(D_80098938)
/* 3415C 80058D5C D4228938 */  ldc1      $f2, %lo(D_80098938)($at)
/* 34160 80058D60 46220002 */  mul.d     $f0, $f0, $f2
/* 34164 80058D64 00000000 */  nop
/* 34168 80058D68 2463FFFF */  addiu     $v1, $v1, -1
/* 3416C 80058D6C 3C0141E0 */  lui       $at, 0x41e0
/* 34170 80058D70 44811800 */  mtc1      $at, $f3
/* 34174 80058D74 44801000 */  mtc1      $zero, $f2
/* 34178 80058D78 00000000 */  nop
/* 3417C 80058D7C 4620103E */  c.le.d    $f2, $f0
/* 34180 80058D80 00000000 */  nop
/* 34184 80058D84 45010005 */  bc1t      .L80058D9C
/* 34188 80058D88 00641821 */   addu     $v1, $v1, $a0
/* 3418C 80058D8C 4620018D */  trunc.w.d $f6, $f0
/* 34190 80058D90 44043000 */  mfc1      $a0, $f6
/* 34194 80058D94 0801636E */  j         .L80058DB8
/* 34198 80058D98 A4A40000 */   sh       $a0, ($a1)
.L80058D9C:
/* 3419C 80058D9C 46220001 */  sub.d     $f0, $f0, $f2
/* 341A0 80058DA0 3C028000 */  lui       $v0, 0x8000
/* 341A4 80058DA4 4620018D */  trunc.w.d $f6, $f0
/* 341A8 80058DA8 44043000 */  mfc1      $a0, $f6
/* 341AC 80058DAC 00000000 */  nop
/* 341B0 80058DB0 00822025 */  or        $a0, $a0, $v0
/* 341B4 80058DB4 A4A40000 */  sh        $a0, ($a1)
.L80058DB8:
/* 341B8 80058DB8 00031400 */  sll       $v0, $v1, 0x10
/* 341BC 80058DBC 03E00008 */  jr        $ra
/* 341C0 80058DC0 00021403 */   sra      $v0, $v0, 0x10
/* 341C4 80058DC4 00000000 */  nop
/* 341C8 80058DC8 00000000 */  nop
/* 341CC 80058DCC 00000000 */  nop
