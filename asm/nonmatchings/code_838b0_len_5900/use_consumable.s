.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel use_consumable
/* 838B0 800EA400 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 838B4 800EA404 AFB10014 */  sw        $s1, 0x14($sp)
/* 838B8 800EA408 0080882D */  daddu     $s1, $a0, $zero
/* 838BC 800EA40C AFB00010 */  sw        $s0, 0x10($sp)
/* 838C0 800EA410 3C108010 */  lui       $s0, 0x8010
/* 838C4 800EA414 26108010 */  addiu     $s0, $s0, -0x7ff0
/* 838C8 800EA418 3C06802C */  lui       $a2, 0x802c
/* 838CC 800EA41C 24C60000 */  addiu     $a2, $a2, 0
/* 838D0 800EA420 AFBF0018 */  sw        $ra, 0x18($sp)
/* 838D4 800EA424 8E040000 */  lw        $a0, ($s0)
/* 838D8 800EA428 8E050004 */  lw        $a1, 4($s0)
/* 838DC 800EA42C 00111040 */  sll       $v0, $s1, 1
/* 838E0 800EA430 3C018011 */  lui       $at, %hi(D_8010CD20)
/* 838E4 800EA434 AC31CD20 */  sw        $s1, %lo(D_8010CD20)($at)
/* 838E8 800EA438 3C118011 */  lui       $s1, %hi(gPlayerData+0x1B4)
/* 838EC 800EA43C 02228821 */  addu      $s1, $s1, $v0
/* 838F0 800EA440 8631F444 */  lh        $s1, %lo(gPlayerData+0x1B4)($s1)
/* 838F4 800EA444 0C00A5CF */  jal       dma_copy
/* 838F8 800EA448 00000000 */   nop      
/* 838FC 800EA44C 24050001 */  addiu     $a1, $zero, 1
/* 83900 800EA450 8E040008 */  lw        $a0, 8($s0)
/* 83904 800EA454 0C0B0CF8 */  jal       start_script
/* 83908 800EA458 0000302D */   daddu    $a2, $zero, $zero
/* 8390C 800EA45C 0040182D */  daddu     $v1, $v0, $zero
/* 83910 800EA460 8C620144 */  lw        $v0, 0x144($v1)
/* 83914 800EA464 AC7100AC */  sw        $s1, 0xac($v1)
/* 83918 800EA468 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8391C 800EA46C 8FB10014 */  lw        $s1, 0x14($sp)
/* 83920 800EA470 8FB00010 */  lw        $s0, 0x10($sp)
/* 83924 800EA474 03E00008 */  jr        $ra
/* 83928 800EA478 27BD0020 */   addiu    $sp, $sp, 0x20
