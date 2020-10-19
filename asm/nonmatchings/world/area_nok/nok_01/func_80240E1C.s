.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E1C
/* 9C61FC 80240E1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C6200 80240E20 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C6204 80240E24 0080802D */  daddu     $s0, $a0, $zero
/* 9C6208 80240E28 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C620C 80240E2C AFB10014 */  sw        $s1, 0x14($sp)
/* 9C6210 80240E30 8E02000C */  lw        $v0, 0xc($s0)
/* 9C6214 80240E34 8C510000 */  lw        $s1, ($v0)
/* 9C6218 80240E38 0C0B1EAF */  jal       get_variable
/* 9C621C 80240E3C 0220282D */   daddu    $a1, $s1, $zero
/* 9C6220 80240E40 3C03FFF0 */  lui       $v1, 0xfff0
/* 9C6224 80240E44 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9C6228 80240E48 0200202D */  daddu     $a0, $s0, $zero
/* 9C622C 80240E4C 00431024 */  and       $v0, $v0, $v1
/* 9C6230 80240E50 00021140 */  sll       $v0, $v0, 5
/* 9C6234 80240E54 3C068008 */  lui       $a2, %hi(gItemTable)
/* 9C6238 80240E58 00C23021 */  addu      $a2, $a2, $v0
/* 9C623C 80240E5C 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 9C6240 80240E60 0C0B2026 */  jal       set_variable
/* 9C6244 80240E64 0220282D */   daddu    $a1, $s1, $zero
/* 9C6248 80240E68 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C624C 80240E6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C6250 80240E70 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C6254 80240E74 24020002 */  addiu     $v0, $zero, 2
/* 9C6258 80240E78 03E00008 */  jr        $ra
/* 9C625C 80240E7C 27BD0020 */   addiu    $sp, $sp, 0x20
