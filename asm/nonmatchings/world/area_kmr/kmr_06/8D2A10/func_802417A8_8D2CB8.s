.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417A8_8D2CB8
/* 8D2CB8 802417A8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8D2CBC 802417AC 2402000D */  addiu     $v0, $zero, 0xd
/* 8D2CC0 802417B0 AFA20010 */  sw        $v0, 0x10($sp)
/* 8D2CC4 802417B4 3C028024 */  lui       $v0, %hi(func_80241500_8D2768)
/* 8D2CC8 802417B8 24421500 */  addiu     $v0, $v0, %lo(func_80241500_8D2768)
/* 8D2CCC 802417BC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8D2CD0 802417C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8D2CD4 802417C4 AFA00018 */  sw        $zero, 0x18($sp)
/* 8D2CD8 802417C8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 8D2CDC 802417CC 0C047644 */  jal       queue_render_task
/* 8D2CE0 802417D0 AFA00014 */   sw       $zero, 0x14($sp)
/* 8D2CE4 802417D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8D2CE8 802417D8 03E00008 */  jr        $ra
/* 8D2CEC 802417DC 27BD0028 */   addiu    $sp, $sp, 0x28
