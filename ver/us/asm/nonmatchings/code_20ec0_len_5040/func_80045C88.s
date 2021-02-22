.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045C88
/* 21088 80045C88 0000202D */  daddu     $a0, $zero, $zero
/* 2108C 80045C8C 24050001 */  addiu     $a1, $zero, 1
/* 21090 80045C90 3C03800A */  lui       $v1, %hi(D_800A0BC0)
/* 21094 80045C94 24630BC0 */  addiu     $v1, $v1, %lo(D_800A0BC0)
.L80045C98:
/* 21098 80045C98 84620010 */  lh        $v0, 0x10($v1)
/* 2109C 80045C9C 14400004 */  bnez      $v0, .L80045CB0
/* 210A0 80045CA0 24840001 */   addiu    $a0, $a0, 1
/* 210A4 80045CA4 A4650010 */  sh        $a1, 0x10($v1)
/* 210A8 80045CA8 03E00008 */  jr        $ra
/* 210AC 80045CAC 0060102D */   daddu    $v0, $v1, $zero
.L80045CB0:
/* 210B0 80045CB0 28820020 */  slti      $v0, $a0, 0x20
/* 210B4 80045CB4 1440FFF8 */  bnez      $v0, .L80045C98
/* 210B8 80045CB8 2463001C */   addiu    $v1, $v1, 0x1c
/* 210BC 80045CBC 03E00008 */  jr        $ra
/* 210C0 80045CC0 0000102D */   daddu    $v0, $zero, $zero
