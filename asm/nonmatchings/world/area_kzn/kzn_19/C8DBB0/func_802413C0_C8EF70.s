.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413C0_C8EF70
/* C8EF70 802413C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C8EF74 802413C4 3C028024 */  lui       $v0, %hi(func_80240E2C_C8E9DC)
/* C8EF78 802413C8 24420E2C */  addiu     $v0, $v0, %lo(func_80240E2C_C8E9DC)
/* C8EF7C 802413CC AFA2001C */  sw        $v0, 0x1c($sp)
/* C8EF80 802413D0 2402000A */  addiu     $v0, $zero, 0xa
/* C8EF84 802413D4 AFA20014 */  sw        $v0, 0x14($sp)
/* C8EF88 802413D8 24020001 */  addiu     $v0, $zero, 1
/* C8EF8C 802413DC 27A40010 */  addiu     $a0, $sp, 0x10
/* C8EF90 802413E0 AFBF0020 */  sw        $ra, 0x20($sp)
/* C8EF94 802413E4 AFA00018 */  sw        $zero, 0x18($sp)
/* C8EF98 802413E8 0C047644 */  jal       queue_render_task
/* C8EF9C 802413EC AFA20010 */   sw       $v0, 0x10($sp)
/* C8EFA0 802413F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* C8EFA4 802413F4 03E00008 */  jr        $ra
/* C8EFA8 802413F8 27BD0028 */   addiu    $sp, $sp, 0x28
