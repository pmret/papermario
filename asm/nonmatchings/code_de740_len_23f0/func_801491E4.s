.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801491E4
/* DF8E4 801491E4 3C06800A */  lui       $a2, 0x800a
/* DF8E8 801491E8 24C6A66C */  addiu     $a2, $a2, -0x5994
/* DF8EC 801491EC 3C02FA00 */  lui       $v0, 0xfa00
/* DF8F0 801491F0 8CC50000 */  lw        $a1, ($a2)
/* DF8F4 801491F4 8FA40014 */  lw        $a0, 0x14($sp)
/* DF8F8 801491F8 00A0182D */  daddu     $v1, $a1, $zero
/* DF8FC 801491FC 24A50008 */  addiu     $a1, $a1, 8
/* DF900 80149200 ACC50000 */  sw        $a1, ($a2)
/* DF904 80149204 AC620000 */  sw        $v0, ($v1)
/* DF908 80149208 308200FF */  andi      $v0, $a0, 0xff
/* DF90C 8014920C AC620004 */  sw        $v0, 4($v1)
/* DF910 80149210 240200FF */  addiu     $v0, $zero, 0xff
/* DF914 80149214 14820005 */  bne       $a0, $v0, .L8014922C
/* DF918 80149218 3C04FCFF */   lui      $a0, 0xfcff
/* DF91C 8014921C 3484FFFF */  ori       $a0, $a0, 0xffff
/* DF920 80149220 3C03FFFD */  lui       $v1, 0xfffd
/* DF924 80149224 0805248E */  j         .L80149238
/* DF928 80149228 34637438 */   ori      $v1, $v1, 0x7438
.L8014922C:
/* DF92C 8014922C 348497FF */  ori       $a0, $a0, 0x97ff
/* DF930 80149230 3C03FFFC */  lui       $v1, 0xfffc
/* DF934 80149234 3463FE38 */  ori       $v1, $v1, 0xfe38
.L80149238:
/* DF938 80149238 24A20008 */  addiu     $v0, $a1, 8
/* DF93C 8014923C ACC20000 */  sw        $v0, ($a2)
/* DF940 80149240 ACA40000 */  sw        $a0, ($a1)
/* DF944 80149244 03E00008 */  jr        $ra
/* DF948 80149248 ACA30004 */   sw       $v1, 4($a1)
/* DF94C 8014924C 00000000 */  nop       
