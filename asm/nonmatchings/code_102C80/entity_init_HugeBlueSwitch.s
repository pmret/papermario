.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_init_HugeBlueSwitch
/* 103C88 802E2408 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 103C8C 802E240C AFB00010 */  sw        $s0, 0x10($sp)
/* 103C90 802E2410 AFBF0014 */  sw        $ra, 0x14($sp)
/* 103C94 802E2414 0C0B88D3 */  jal       func_802E234C
/* 103C98 802E2418 0080802D */   daddu    $s0, $a0, $zero
/* 103C9C 802E241C 3C014040 */  lui       $at, 0x4040
/* 103CA0 802E2420 44810000 */  mtc1      $at, $f0
/* 103CA4 802E2424 8E020040 */  lw        $v0, 0x40($s0)
/* 103CA8 802E2428 E6000054 */  swc1      $f0, 0x54($s0)
/* 103CAC 802E242C E6000058 */  swc1      $f0, 0x58($s0)
/* 103CB0 802E2430 E600005C */  swc1      $f0, 0x5c($s0)
/* 103CB4 802E2434 E4400014 */  swc1      $f0, 0x14($v0)
/* 103CB8 802E2438 E4400018 */  swc1      $f0, 0x18($v0)
/* 103CBC 802E243C E440001C */  swc1      $f0, 0x1c($v0)
/* 103CC0 802E2440 8FBF0014 */  lw        $ra, 0x14($sp)
/* 103CC4 802E2444 8FB00010 */  lw        $s0, 0x10($sp)
/* 103CC8 802E2448 03E00008 */  jr        $ra
/* 103CCC 802E244C 27BD0018 */   addiu    $sp, $sp, 0x18
