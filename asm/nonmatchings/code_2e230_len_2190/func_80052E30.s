.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052E30
/* 2E230 80052E30 308400FF */  andi      $a0, $a0, 0xff
/* 2E234 80052E34 000410C0 */  sll       $v0, $a0, 3
/* 2E238 80052E38 00441021 */  addu      $v0, $v0, $a0
/* 2E23C 80052E3C 000210C0 */  sll       $v0, $v0, 3
/* 2E240 80052E40 3C03800A */  lui       $v1, %hi(D_8009A5C0)
/* 2E244 80052E44 8C63A5C0 */  lw        $v1, %lo(D_8009A5C0)($v1)
/* 2E248 80052E48 24421320 */  addiu     $v0, $v0, 0x1320
/* 2E24C 80052E4C 00621821 */  addu      $v1, $v1, $v0
/* 2E250 80052E50 AC60001C */  sw        $zero, 0x1c($v1)
/* 2E254 80052E54 03E00008 */  jr        $ra
/* 2E258 80052E58 A0600045 */   sb       $zero, 0x45($v1)
