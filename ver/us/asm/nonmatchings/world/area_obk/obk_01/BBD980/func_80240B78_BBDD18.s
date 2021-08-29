.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B78_BBDD18
/* BBDD18 80240B78 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBDD1C 80240B7C AFBF0010 */  sw        $ra, 0x10($sp)
/* BBDD20 80240B80 8C82000C */  lw        $v0, 0xc($a0)
/* BBDD24 80240B84 0C0B1EAF */  jal       evt_get_variable
/* BBDD28 80240B88 8C450000 */   lw       $a1, ($v0)
/* BBDD2C 80240B8C 3C018024 */  lui       $at, %hi(D_80244158_BC12F8)
/* BBDD30 80240B90 AC224158 */  sw        $v0, %lo(D_80244158_BC12F8)($at)
/* BBDD34 80240B94 24020002 */  addiu     $v0, $zero, 2
/* BBDD38 80240B98 8FBF0010 */  lw        $ra, 0x10($sp)
/* BBDD3C 80240B9C 24030001 */  addiu     $v1, $zero, 1
/* BBDD40 80240BA0 3C018024 */  lui       $at, %hi(D_80244154_BC12F4)
/* BBDD44 80240BA4 AC234154 */  sw        $v1, %lo(D_80244154_BC12F4)($at)
/* BBDD48 80240BA8 03E00008 */  jr        $ra
/* BBDD4C 80240BAC 27BD0018 */   addiu    $sp, $sp, 0x18
