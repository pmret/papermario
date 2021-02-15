.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80125C84
/* BC384 80125C84 288200F0 */  slti      $v0, $a0, 0xf0
/* BC388 80125C88 44871000 */  mtc1      $a3, $f2
/* BC38C 80125C8C 8FA70010 */  lw        $a3, 0x10($sp)
/* BC390 80125C90 93A30017 */  lbu       $v1, 0x17($sp)
/* BC394 80125C94 14400004 */  bnez      $v0, .L80125CA8
/* BC398 80125C98 2482FF09 */   addiu    $v0, $a0, -0xf7
/* BC39C 80125C9C 2C420003 */  sltiu     $v0, $v0, 3
/* BC3A0 80125CA0 10400036 */  beqz      $v0, .L80125D7C
/* BC3A4 80125CA4 0000102D */   daddu    $v0, $zero, $zero
.L80125CA8:
/* BC3A8 80125CA8 10E00005 */  beqz      $a3, .L80125CC0
/* BC3AC 80125CAC 240200F7 */   addiu    $v0, $zero, 0xf7
/* BC3B0 80125CB0 44870000 */  mtc1      $a3, $f0
/* BC3B4 80125CB4 00000000 */  nop
/* BC3B8 80125CB8 08049754 */  j         .L80125D50
/* BC3BC 80125CBC 46800020 */   cvt.s.w  $f0, $f0
.L80125CC0:
/* BC3C0 80125CC0 10600015 */  beqz      $v1, .L80125D18
/* BC3C4 80125CC4 00051880 */   sll      $v1, $a1, 2
/* BC3C8 80125CC8 00061040 */  sll       $v0, $a2, 1
/* BC3CC 80125CCC 3C01802F */  lui       $at, %hi(D_802EB5A8)
/* BC3D0 80125CD0 00230821 */  addu      $at, $at, $v1
/* BC3D4 80125CD4 8C23B5A8 */  lw        $v1, %lo(D_802EB5A8)($at)
/* BC3D8 80125CD8 00461021 */  addu      $v0, $v0, $a2
/* BC3DC 80125CDC 8C630008 */  lw        $v1, 8($v1)
/* BC3E0 80125CE0 00021080 */  sll       $v0, $v0, 2
/* BC3E4 80125CE4 00431021 */  addu      $v0, $v0, $v1
/* BC3E8 80125CE8 8C430004 */  lw        $v1, 4($v0)
/* BC3EC 80125CEC 1060000A */  beqz      $v1, .L80125D18
/* BC3F0 80125CF0 240200F7 */   addiu    $v0, $zero, 0xf7
/* BC3F4 80125CF4 10820008 */  beq       $a0, $v0, .L80125D18
/* BC3F8 80125CF8 240200F8 */   addiu    $v0, $zero, 0xf8
/* BC3FC 80125CFC 10820006 */  beq       $a0, $v0, .L80125D18
/* BC400 80125D00 240200F9 */   addiu    $v0, $zero, 0xf9
/* BC404 80125D04 10820004 */  beq       $a0, $v0, .L80125D18
/* BC408 80125D08 00641021 */   addu     $v0, $v1, $a0
/* BC40C 80125D0C 90420000 */  lbu       $v0, ($v0)
/* BC410 80125D10 08049750 */  j         .L80125D40
/* BC414 80125D14 00000000 */   nop
.L80125D18:
/* BC418 80125D18 00051880 */  sll       $v1, $a1, 2
/* BC41C 80125D1C 00061040 */  sll       $v0, $a2, 1
/* BC420 80125D20 3C01802F */  lui       $at, %hi(D_802EB5A8)
/* BC424 80125D24 00230821 */  addu      $at, $at, $v1
/* BC428 80125D28 8C23B5A8 */  lw        $v1, %lo(D_802EB5A8)($at)
/* BC42C 80125D2C 00461021 */  addu      $v0, $v0, $a2
/* BC430 80125D30 8C630008 */  lw        $v1, 8($v1)
/* BC434 80125D34 00021080 */  sll       $v0, $v0, 2
/* BC438 80125D38 00431021 */  addu      $v0, $v0, $v1
/* BC43C 80125D3C 90420008 */  lbu       $v0, 8($v0)
.L80125D40:
/* BC440 80125D40 44820000 */  mtc1      $v0, $f0
/* BC444 80125D44 00000000 */  nop
/* BC448 80125D48 46800020 */  cvt.s.w   $f0, $f0
/* BC44C 80125D4C 240200F7 */  addiu     $v0, $zero, 0xf7
.L80125D50:
/* BC450 80125D50 1482000C */  bne       $a0, $v0, .L80125D84
/* BC454 80125D54 240200F8 */   addiu    $v0, $zero, 0xf8
/* BC458 80125D58 46020002 */  mul.s     $f0, $f0, $f2
/* BC45C 80125D5C 00000000 */  nop
/* BC460 80125D60 3C018015 */  lui       $at, %hi(D_80150578)
/* BC464 80125D64 D4220578 */  ldc1      $f2, %lo(D_80150578)($at)
/* BC468 80125D68 46000021 */  cvt.d.s   $f0, $f0
.L80125D6C:
/* BC46C 80125D6C 46220002 */  mul.d     $f0, $f0, $f2
/* BC470 80125D70 00000000 */  nop
/* BC474 80125D74 4620010D */  trunc.w.d $f4, $f0
/* BC478 80125D78 44022000 */  mfc1      $v0, $f4
.L80125D7C:
/* BC47C 80125D7C 03E00008 */  jr        $ra
/* BC480 80125D80 00000000 */   nop
.L80125D84:
/* BC484 80125D84 14820008 */  bne       $a0, $v0, .L80125DA8
/* BC488 80125D88 240200F9 */   addiu    $v0, $zero, 0xf9
/* BC48C 80125D8C 46020002 */  mul.s     $f0, $f0, $f2
/* BC490 80125D90 00000000 */  nop
/* BC494 80125D94 46000021 */  cvt.d.s   $f0, $f0
/* BC498 80125D98 4620010D */  trunc.w.d $f4, $f0
/* BC49C 80125D9C 44022000 */  mfc1      $v0, $f4
/* BC4A0 80125DA0 03E00008 */  jr        $ra
/* BC4A4 80125DA4 00000000 */   nop
.L80125DA8:
/* BC4A8 80125DA8 14820008 */  bne       $a0, $v0, .L80125DCC
/* BC4AC 80125DAC 288200F0 */   slti     $v0, $a0, 0xf0
/* BC4B0 80125DB0 46020002 */  mul.s     $f0, $f0, $f2
/* BC4B4 80125DB4 00000000 */  nop
/* BC4B8 80125DB8 3C013FE0 */  lui       $at, 0x3fe0
/* BC4BC 80125DBC 44811800 */  mtc1      $at, $f3
/* BC4C0 80125DC0 44801000 */  mtc1      $zero, $f2
/* BC4C4 80125DC4 0804975B */  j         .L80125D6C
/* BC4C8 80125DC8 46000021 */   cvt.d.s  $f0, $f0
.L80125DCC:
/* BC4CC 80125DCC 10400007 */  beqz      $v0, .L80125DEC
/* BC4D0 80125DD0 00000000 */   nop
/* BC4D4 80125DD4 46020002 */  mul.s     $f0, $f0, $f2
/* BC4D8 80125DD8 00000000 */  nop
/* BC4DC 80125DDC 4600010D */  trunc.w.s $f4, $f0
/* BC4E0 80125DE0 44022000 */  mfc1      $v0, $f4
/* BC4E4 80125DE4 03E00008 */  jr        $ra
/* BC4E8 80125DE8 00000000 */   nop
.L80125DEC:
/* BC4EC 80125DEC 03E00008 */  jr        $ra
/* BC4F0 80125DF0 0000102D */   daddu    $v0, $zero, $zero
