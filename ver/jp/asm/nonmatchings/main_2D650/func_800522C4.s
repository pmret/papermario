.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800522C4
/* 2D6C4 800522C4 0000282D */  daddu     $a1, $zero, $zero
/* 2D6C8 800522C8 24060080 */  addiu     $a2, $zero, 0x80
/* 2D6CC 800522CC 24031320 */  addiu     $v1, $zero, 0x1320
.L800522D0:
/* 2D6D0 800522D0 00831021 */  addu      $v0, $a0, $v1
/* 2D6D4 800522D4 24A50001 */  addiu     $a1, $a1, 1
/* 2D6D8 800522D8 AC40001C */  sw        $zero, 0x1c($v0)
/* 2D6DC 800522DC AC400020 */  sw        $zero, 0x20($v0)
/* 2D6E0 800522E0 AC400024 */  sw        $zero, 0x24($v0)
/* 2D6E4 800522E4 AC400028 */  sw        $zero, 0x28($v0)
/* 2D6E8 800522E8 A040003B */  sb        $zero, 0x3b($v0)
/* 2D6EC 800522EC A040003C */  sb        $zero, 0x3c($v0)
/* 2D6F0 800522F0 A040003D */  sb        $zero, 0x3d($v0)
/* 2D6F4 800522F4 A040003E */  sb        $zero, 0x3e($v0)
/* 2D6F8 800522F8 A046003F */  sb        $a2, 0x3f($v0)
/* 2D6FC 800522FC 28A20018 */  slti      $v0, $a1, 0x18
/* 2D700 80052300 1440FFF3 */  bnez      $v0, .L800522D0
/* 2D704 80052304 24630048 */   addiu    $v1, $v1, 0x48
/* 2D708 80052308 03E00008 */  jr        $ra
/* 2D70C 8005230C 00000000 */   nop
