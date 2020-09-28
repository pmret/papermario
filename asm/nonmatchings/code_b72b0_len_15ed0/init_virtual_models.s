.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel init_virtual_models
/* B7358 80120C58 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B735C 80120C5C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B7360 80120C60 80420070 */  lb        $v0, 0x70($v0)
/* B7364 80120C64 14400005 */  bnez      $v0, .L80120C7C
/* B7368 80120C68 00000000 */   nop      
/* B736C 80120C6C 3C028015 */  lui       $v0, 0x8015
/* B7370 80120C70 24423B70 */  addiu     $v0, $v0, 0x3b70
/* B7374 80120C74 08048321 */  j         .L80120C84
/* B7378 80120C78 00000000 */   nop      
.L80120C7C:
/* B737C 80120C7C 3C028015 */  lui       $v0, 0x8015
/* B7380 80120C80 24423F70 */  addiu     $v0, $v0, 0x3f70
.L80120C84:
/* B7384 80120C84 3C018015 */  lui       $at, 0x8015
/* B7388 80120C88 AC224370 */  sw        $v0, 0x4370($at)
/* B738C 80120C8C 2402000A */  addiu     $v0, $zero, 0xa
/* B7390 80120C90 3C018015 */  lui       $at, 0x8015
/* B7394 80120C94 AC22437C */  sw        $v0, 0x437c($at)
/* B7398 80120C98 3C018015 */  lui       $at, 0x8015
/* B739C 80120C9C AC224380 */  sw        $v0, 0x4380($at)
/* B73A0 80120CA0 3C018015 */  lui       $at, 0x8015
/* B73A4 80120CA4 AC224384 */  sw        $v0, 0x4384($at)
/* B73A8 80120CA8 3C018015 */  lui       $at, 0x8015
/* B73AC 80120CAC AC224388 */  sw        $v0, 0x4388($at)
/* B73B0 80120CB0 24020320 */  addiu     $v0, $zero, 0x320
/* B73B4 80120CB4 3C018015 */  lui       $at, 0x8015
/* B73B8 80120CB8 AC22438C */  sw        $v0, 0x438c($at)
/* B73BC 80120CBC 240203E8 */  addiu     $v0, $zero, 0x3e8
/* B73C0 80120CC0 3C018015 */  lui       $at, 0x8015
/* B73C4 80120CC4 AC201318 */  sw        $zero, 0x1318($at)
/* B73C8 80120CC8 3C018015 */  lui       $at, 0x8015
/* B73CC 80120CCC AC204378 */  sw        $zero, 0x4378($at)
/* B73D0 80120CD0 3C018015 */  lui       $at, 0x8015
/* B73D4 80120CD4 AC224390 */  sw        $v0, 0x4390($at)
/* B73D8 80120CD8 03E00008 */  jr        $ra
/* B73DC 80120CDC 00000000 */   nop      
