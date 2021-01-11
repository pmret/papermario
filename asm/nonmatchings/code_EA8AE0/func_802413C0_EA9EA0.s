.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413C0_EA9EA0
/* EA9EA0 802413C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EA9EA4 802413C4 3C028024 */  lui       $v0, %hi(func_80240E2C_EA990C)
/* EA9EA8 802413C8 24420E2C */  addiu     $v0, $v0, %lo(func_80240E2C_EA990C)
/* EA9EAC 802413CC AFA2001C */  sw        $v0, 0x1c($sp)
/* EA9EB0 802413D0 2402000A */  addiu     $v0, $zero, 0xa
/* EA9EB4 802413D4 AFA20014 */  sw        $v0, 0x14($sp)
/* EA9EB8 802413D8 24020001 */  addiu     $v0, $zero, 1
/* EA9EBC 802413DC 27A40010 */  addiu     $a0, $sp, 0x10
/* EA9EC0 802413E0 AFBF0020 */  sw        $ra, 0x20($sp)
/* EA9EC4 802413E4 AFA00018 */  sw        $zero, 0x18($sp)
/* EA9EC8 802413E8 0C04A144 */  jal       func_80128510
/* EA9ECC 802413EC AFA20010 */   sw       $v0, 0x10($sp)
/* EA9ED0 802413F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* EA9ED4 802413F4 03E00008 */  jr        $ra
/* EA9ED8 802413F8 27BD0028 */   addiu    $sp, $sp, 0x28
