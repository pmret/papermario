.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188B0_59EF90
/* 59EF90 802188B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 59EF94 802188B4 3C028022 */  lui       $v0, %hi(func_8021835C_59E18C)
/* 59EF98 802188B8 2442835C */  addiu     $v0, $v0, %lo(func_8021835C_59E18C)
/* 59EF9C 802188BC AFA2001C */  sw        $v0, 0x1c($sp)
/* 59EFA0 802188C0 2402000A */  addiu     $v0, $zero, 0xa
/* 59EFA4 802188C4 AFA20014 */  sw        $v0, 0x14($sp)
/* 59EFA8 802188C8 24020001 */  addiu     $v0, $zero, 1
/* 59EFAC 802188CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 59EFB0 802188D0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 59EFB4 802188D4 AFA00018 */  sw        $zero, 0x18($sp)
/* 59EFB8 802188D8 0C047644 */  jal       queue_render_task
/* 59EFBC 802188DC AFA20010 */   sw       $v0, 0x10($sp)
/* 59EFC0 802188E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 59EFC4 802188E4 03E00008 */  jr        $ra
/* 59EFC8 802188E8 27BD0028 */   addiu    $sp, $sp, 0x28
