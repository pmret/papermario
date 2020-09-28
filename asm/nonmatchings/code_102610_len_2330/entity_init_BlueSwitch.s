.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_init_BlueSwitch
/* 103C00 802E2380 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 103C04 802E2384 AFB00010 */  sw        $s0, 0x10($sp)
/* 103C08 802E2388 0080802D */  daddu     $s0, $a0, $zero
/* 103C0C 802E238C AFBF0018 */  sw        $ra, 0x18($sp)
/* 103C10 802E2390 AFB10014 */  sw        $s1, 0x14($sp)
/* 103C14 802E2394 0C0B88D3 */  jal       func_802E234C
/* 103C18 802E2398 8E110040 */   lw       $s1, 0x40($s0)
/* 103C1C 802E239C 3C038016 */  lui       $v1, 0x8016
/* 103C20 802E23A0 8C63C7D0 */  lw        $v1, -0x3830($v1)
/* 103C24 802E23A4 24020002 */  addiu     $v0, $zero, 2
/* 103C28 802E23A8 14620005 */  bne       $v1, $v0, .L802E23C0
/* 103C2C 802E23AC 24020001 */   addiu    $v0, $zero, 1
/* 103C30 802E23B0 3C01802F */  lui       $at, 0x802f
/* 103C34 802E23B4 AC30B3A0 */  sw        $s0, -0x4c60($at)
/* 103C38 802E23B8 080B88FD */  j         .L802E23F4
/* 103C3C 802E23BC 00000000 */   nop      
.L802E23C0:
/* 103C40 802E23C0 1462000A */  bne       $v1, $v0, .L802E23EC
/* 103C44 802E23C4 00000000 */   nop      
/* 103C48 802E23C8 3C02802F */  lui       $v0, 0x802f
/* 103C4C 802E23CC 8C42B3A0 */  lw        $v0, -0x4c60($v0)
/* 103C50 802E23D0 10400008 */  beqz      $v0, .L802E23F4
/* 103C54 802E23D4 00000000 */   nop      
/* 103C58 802E23D8 AE220028 */  sw        $v0, 0x28($s1)
/* 103C5C 802E23DC 8E020000 */  lw        $v0, ($s0)
/* 103C60 802E23E0 34420001 */  ori       $v0, $v0, 1
/* 103C64 802E23E4 080B88FD */  j         .L802E23F4
/* 103C68 802E23E8 AE020000 */   sw       $v0, ($s0)
.L802E23EC:
/* 103C6C 802E23EC 3C01802F */  lui       $at, 0x802f
/* 103C70 802E23F0 AC20B3A0 */  sw        $zero, -0x4c60($at)
.L802E23F4:
/* 103C74 802E23F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 103C78 802E23F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 103C7C 802E23FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 103C80 802E2400 03E00008 */  jr        $ra
/* 103C84 802E2404 27BD0020 */   addiu    $sp, $sp, 0x20
