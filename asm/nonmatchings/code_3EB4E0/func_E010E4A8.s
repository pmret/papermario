.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E010E4A8
/* 3EB988 E010E4A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3EB98C E010E4AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 3EB990 E010E4B0 8C830000 */  lw        $v1, ($a0)
/* 3EB994 E010E4B4 8C85000C */  lw        $a1, 0xc($a0)
/* 3EB998 E010E4B8 30620010 */  andi      $v0, $v1, 0x10
/* 3EB99C E010E4BC 10400005 */  beqz      $v0, .LE010E4D4
/* 3EB9A0 E010E4C0 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3EB9A4 E010E4C4 00621024 */  and       $v0, $v1, $v0
/* 3EB9A8 E010E4C8 AC820000 */  sw        $v0, ($a0)
/* 3EB9AC E010E4CC 24020010 */  addiu     $v0, $zero, 0x10
/* 3EB9B0 E010E4D0 ACA20018 */  sw        $v0, 0x18($a1)
.LE010E4D4:
/* 3EB9B4 E010E4D4 8CA30018 */  lw        $v1, 0x18($a1)
/* 3EB9B8 E010E4D8 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3EB9BC E010E4DC 10400002 */  beqz      $v0, .LE010E4E8
/* 3EB9C0 E010E4E0 2462FFFF */   addiu    $v0, $v1, -1
/* 3EB9C4 E010E4E4 ACA20018 */  sw        $v0, 0x18($a1)
.LE010E4E8:
/* 3EB9C8 E010E4E8 8CA2001C */  lw        $v0, 0x1c($a1)
/* 3EB9CC E010E4EC 8CA30018 */  lw        $v1, 0x18($a1)
/* 3EB9D0 E010E4F0 24420001 */  addiu     $v0, $v0, 1
/* 3EB9D4 E010E4F4 04610003 */  bgez      $v1, .LE010E504
/* 3EB9D8 E010E4F8 ACA2001C */   sw       $v0, 0x1c($a1)
/* 3EB9DC E010E4FC 0C080128 */  jal       func_E02004A0
/* 3EB9E0 E010E500 00000000 */   nop      
.LE010E504:
/* 3EB9E4 E010E504 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3EB9E8 E010E508 03E00008 */  jr        $ra
/* 3EB9EC E010E50C 27BD0018 */   addiu    $sp, $sp, 0x18
