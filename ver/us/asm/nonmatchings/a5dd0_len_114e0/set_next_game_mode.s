.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_next_game_mode
/* A92BC 80112BBC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A92C0 80112BC0 AFB00010 */  sw        $s0, 0x10($sp)
/* A92C4 80112BC4 3C108015 */  lui       $s0, %hi(gMainGameState)
/* A92C8 80112BC8 26101700 */  addiu     $s0, $s0, %lo(gMainGameState)
/* A92CC 80112BCC 0000182D */  daddu     $v1, $zero, $zero
/* A92D0 80112BD0 AFBF0014 */  sw        $ra, 0x14($sp)
.L80112BD4:
/* A92D4 80112BD4 96020000 */  lhu       $v0, ($s0)
/* A92D8 80112BD8 10400006 */  beqz      $v0, .L80112BF4
/* A92DC 80112BDC 28620002 */   slti     $v0, $v1, 2
/* A92E0 80112BE0 24630001 */  addiu     $v1, $v1, 1
/* A92E4 80112BE4 28620002 */  slti      $v0, $v1, 2
/* A92E8 80112BE8 1440FFFA */  bnez      $v0, .L80112BD4
/* A92EC 80112BEC 26100018 */   addiu    $s0, $s0, 0x18
/* A92F0 80112BF0 28620002 */  slti      $v0, $v1, 2
.L80112BF4:
/* A92F4 80112BF4 14400003 */  bnez      $v0, .L80112C04
/* A92F8 80112BF8 24020003 */   addiu    $v0, $zero, 3
.L80112BFC:
/* A92FC 80112BFC 08044AFF */  j         .L80112BFC
/* A9300 80112C00 00000000 */   nop
.L80112C04:
/* A9304 80112C04 A6020000 */  sh        $v0, ($s0)
/* A9308 80112C08 8C820004 */  lw        $v0, 4($a0)
/* A930C 80112C0C AE020004 */  sw        $v0, 4($s0)
/* A9310 80112C10 8C820008 */  lw        $v0, 8($a0)
/* A9314 80112C14 8E030004 */  lw        $v1, 4($s0)
/* A9318 80112C18 AE020008 */  sw        $v0, 8($s0)
/* A931C 80112C1C 8C820010 */  lw        $v0, 0x10($a0)
/* A9320 80112C20 AE00000C */  sw        $zero, 0xc($s0)
/* A9324 80112C24 14600004 */  bnez      $v1, .L80112C38
/* A9328 80112C28 AE020010 */   sw       $v0, 0x10($s0)
/* A932C 80112C2C 3C028011 */  lui       $v0, %hi(state_delegate_NOP)
/* A9330 80112C30 24422B90 */  addiu     $v0, $v0, %lo(state_delegate_NOP)
/* A9334 80112C34 AE020004 */  sw        $v0, 4($s0)
.L80112C38:
/* A9338 80112C38 8E020008 */  lw        $v0, 8($s0)
/* A933C 80112C3C 14400004 */  bnez      $v0, .L80112C50
/* A9340 80112C40 00000000 */   nop
/* A9344 80112C44 3C028011 */  lui       $v0, %hi(state_delegate_NOP)
/* A9348 80112C48 24422B90 */  addiu     $v0, $v0, %lo(state_delegate_NOP)
/* A934C 80112C4C AE020008 */  sw        $v0, 8($s0)
.L80112C50:
/* A9350 80112C50 8E02000C */  lw        $v0, 0xc($s0)
/* A9354 80112C54 14400004 */  bnez      $v0, .L80112C68
/* A9358 80112C58 00000000 */   nop
/* A935C 80112C5C 3C028011 */  lui       $v0, %hi(state_delegate_NOP)
/* A9360 80112C60 24422B90 */  addiu     $v0, $v0, %lo(state_delegate_NOP)
/* A9364 80112C64 AE02000C */  sw        $v0, 0xc($s0)
.L80112C68:
/* A9368 80112C68 8E020010 */  lw        $v0, 0x10($s0)
/* A936C 80112C6C 14400004 */  bnez      $v0, .L80112C80
/* A9370 80112C70 00000000 */   nop
/* A9374 80112C74 3C028011 */  lui       $v0, %hi(state_delegate_NOP)
/* A9378 80112C78 24422B90 */  addiu     $v0, $v0, %lo(state_delegate_NOP)
/* A937C 80112C7C AE020010 */  sw        $v0, 0x10($s0)
.L80112C80:
/* A9380 80112C80 8E030004 */  lw        $v1, 4($s0)
/* A9384 80112C84 3C028011 */  lui       $v0, %hi(state_delegate_NOP)
/* A9388 80112C88 24422B90 */  addiu     $v0, $v0, %lo(state_delegate_NOP)
/* A938C 80112C8C 0060F809 */  jalr      $v1
/* A9390 80112C90 AE020014 */   sw       $v0, 0x14($s0)
/* A9394 80112C94 0200102D */  daddu     $v0, $s0, $zero
/* A9398 80112C98 8FBF0014 */  lw        $ra, 0x14($sp)
/* A939C 80112C9C 8FB00010 */  lw        $s0, 0x10($sp)
/* A93A0 80112CA0 03E00008 */  jr        $ra
/* A93A4 80112CA4 27BD0018 */   addiu    $sp, $sp, 0x18
