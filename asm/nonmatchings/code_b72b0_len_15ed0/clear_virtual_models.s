.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_virtual_models
/* B72B0 80120BB0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B72B4 80120BB4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B72B8 80120BB8 80420070 */  lb        $v0, 0x70($v0)
/* B72BC 80120BBC 14400005 */  bnez      $v0, .L80120BD4
/* B72C0 80120BC0 00000000 */   nop      
/* B72C4 80120BC4 3C028015 */  lui       $v0, 0x8015
/* B72C8 80120BC8 24423B70 */  addiu     $v0, $v0, 0x3b70
/* B72CC 80120BCC 080482F7 */  j         .L80120BDC
/* B72D0 80120BD0 00000000 */   nop      
.L80120BD4:
/* B72D4 80120BD4 3C028015 */  lui       $v0, 0x8015
/* B72D8 80120BD8 24423F70 */  addiu     $v0, $v0, 0x3f70
.L80120BDC:
/* B72DC 80120BDC 3C018015 */  lui       $at, 0x8015
/* B72E0 80120BE0 AC224370 */  sw        $v0, 0x4370($at)
/* B72E4 80120BE4 3C028015 */  lui       $v0, 0x8015
/* B72E8 80120BE8 8C424370 */  lw        $v0, 0x4370($v0)
/* B72EC 80120BEC 240300FF */  addiu     $v1, $zero, 0xff
/* B72F0 80120BF0 244203FC */  addiu     $v0, $v0, 0x3fc
.L80120BF4:
/* B72F4 80120BF4 AC400000 */  sw        $zero, ($v0)
/* B72F8 80120BF8 2463FFFF */  addiu     $v1, $v1, -1
/* B72FC 80120BFC 0461FFFD */  bgez      $v1, .L80120BF4
/* B7300 80120C00 2442FFFC */   addiu    $v0, $v0, -4
/* B7304 80120C04 2402000A */  addiu     $v0, $zero, 0xa
/* B7308 80120C08 3C018015 */  lui       $at, 0x8015
/* B730C 80120C0C AC22437C */  sw        $v0, 0x437c($at)
/* B7310 80120C10 3C018015 */  lui       $at, 0x8015
/* B7314 80120C14 AC224380 */  sw        $v0, 0x4380($at)
/* B7318 80120C18 3C018015 */  lui       $at, 0x8015
/* B731C 80120C1C AC224384 */  sw        $v0, 0x4384($at)
/* B7320 80120C20 3C018015 */  lui       $at, 0x8015
/* B7324 80120C24 AC224388 */  sw        $v0, 0x4388($at)
/* B7328 80120C28 24020320 */  addiu     $v0, $zero, 0x320
/* B732C 80120C2C 3C018015 */  lui       $at, 0x8015
/* B7330 80120C30 AC22438C */  sw        $v0, 0x438c($at)
/* B7334 80120C34 240203E8 */  addiu     $v0, $zero, 0x3e8
/* B7338 80120C38 3C018015 */  lui       $at, 0x8015
/* B733C 80120C3C AC201318 */  sw        $zero, 0x1318($at)
/* B7340 80120C40 3C018015 */  lui       $at, 0x8015
/* B7344 80120C44 AC204378 */  sw        $zero, 0x4378($at)
/* B7348 80120C48 3C018015 */  lui       $at, 0x8015
/* B734C 80120C4C AC224390 */  sw        $v0, 0x4390($at)
/* B7350 80120C50 03E00008 */  jr        $ra
/* B7354 80120C54 00000000 */   nop      
