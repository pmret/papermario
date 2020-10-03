.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004778C
/* 22B8C 8004778C 00041040 */  sll       $v0, $a0, 1
/* 22B90 80047790 00441021 */  addu      $v0, $v0, $a0
/* 22B94 80047794 00021080 */  sll       $v0, $v0, 2
/* 22B98 80047798 00441023 */  subu      $v0, $v0, $a0
/* 22B9C 8004779C 3C03800A */  lui       $v1, 0x800a
/* 22BA0 800477A0 8C630F44 */  lw        $v1, 0xf44($v1)
/* 22BA4 800477A4 00021100 */  sll       $v0, $v0, 4
/* 22BA8 800477A8 00621821 */  addu      $v1, $v1, $v0
/* 22BAC 800477AC AC650004 */  sw        $a1, 4($v1)
/* 22BB0 800477B0 AC660008 */  sw        $a2, 8($v1)
/* 22BB4 800477B4 AC67000C */  sw        $a3, 0xc($v1)
/* 22BB8 800477B8 8FA40018 */  lw        $a0, 0x18($sp)
/* 22BBC 800477BC 8FA5001C */  lw        $a1, 0x1c($sp)
/* 22BC0 800477C0 24840011 */  addiu     $a0, $a0, 0x11
/* 22BC4 800477C4 24A20011 */  addiu     $v0, $a1, 0x11
/* 22BC8 800477C8 AC62001C */  sw        $v0, 0x1c($v1)
/* 22BCC 800477CC 24A20022 */  addiu     $v0, $a1, 0x22
/* 22BD0 800477D0 AC650014 */  sw        $a1, 0x14($v1)
/* 22BD4 800477D4 24A50033 */  addiu     $a1, $a1, 0x33
/* 22BD8 800477D8 AC640010 */  sw        $a0, 0x10($v1)
/* 22BDC 800477DC AC640018 */  sw        $a0, 0x18($v1)
/* 22BE0 800477E0 AC640020 */  sw        $a0, 0x20($v1)
/* 22BE4 800477E4 AC620024 */  sw        $v0, 0x24($v1)
/* 22BE8 800477E8 AC640028 */  sw        $a0, 0x28($v1)
/* 22BEC 800477EC 03E00008 */  jr        $ra
/* 22BF0 800477F0 AC65002C */   sw       $a1, 0x2c($v1)
