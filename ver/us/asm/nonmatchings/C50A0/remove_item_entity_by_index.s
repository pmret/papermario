.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80150DA0
.word L80133A48_CA148, L80133A50_CA150, L80133A50_CA150, L80133A48_CA148, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A48_CA148, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A48_CA148, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A48_CA148, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A50_CA150, L80133A48_CA148, 0

.section .text

glabel remove_item_entity_by_index
/* CA0FC 801339FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CA100 80133A00 AFB00010 */  sw        $s0, 0x10($sp)
/* CA104 80133A04 0080802D */  daddu     $s0, $a0, $zero
/* CA108 80133A08 3C028015 */  lui       $v0, %hi(D_801565A0)
/* CA10C 80133A0C 8C4265A0 */  lw        $v0, %lo(D_801565A0)($v0)
/* CA110 80133A10 00101880 */  sll       $v1, $s0, 2
/* CA114 80133A14 AFBF0018 */  sw        $ra, 0x18($sp)
/* CA118 80133A18 AFB10014 */  sw        $s1, 0x14($sp)
/* CA11C 80133A1C 00621821 */  addu      $v1, $v1, $v0
/* CA120 80133A20 8C630000 */  lw        $v1, ($v1)
/* CA124 80133A24 8064001B */  lb        $a0, 0x1b($v1)
/* CA128 80133A28 2C82001D */  sltiu     $v0, $a0, 0x1d
/* CA12C 80133A2C 10400008 */  beqz      $v0, L80133A50_CA150
/* CA130 80133A30 00041080 */   sll      $v0, $a0, 2
/* CA134 80133A34 3C018015 */  lui       $at, %hi(jtbl_80150DA0)
/* CA138 80133A38 00220821 */  addu      $at, $at, $v0
/* CA13C 80133A3C 8C220DA0 */  lw        $v0, %lo(jtbl_80150DA0)($at)
/* CA140 80133A40 00400008 */  jr        $v0
/* CA144 80133A44 00000000 */   nop
glabel L80133A48_CA148
/* CA148 80133A48 0C0448CA */  jal       delete_shadow
/* CA14C 80133A4C 84640020 */   lh       $a0, 0x20($v1)
glabel L80133A50_CA150
/* CA150 80133A50 3C118015 */  lui       $s1, %hi(D_801565A0)
/* CA154 80133A54 263165A0 */  addiu     $s1, $s1, %lo(D_801565A0)
/* CA158 80133A58 8E220000 */  lw        $v0, ($s1)
/* CA15C 80133A5C 00108080 */  sll       $s0, $s0, 2
/* CA160 80133A60 02021021 */  addu      $v0, $s0, $v0
/* CA164 80133A64 0C00AB4B */  jal       heap_free
/* CA168 80133A68 8C440000 */   lw       $a0, ($v0)
/* CA16C 80133A6C 8E220000 */  lw        $v0, ($s1)
/* CA170 80133A70 02028021 */  addu      $s0, $s0, $v0
/* CA174 80133A74 AE000000 */  sw        $zero, ($s0)
/* CA178 80133A78 8FBF0018 */  lw        $ra, 0x18($sp)
/* CA17C 80133A7C 8FB10014 */  lw        $s1, 0x14($sp)
/* CA180 80133A80 8FB00010 */  lw        $s0, 0x10($sp)
/* CA184 80133A84 3C018015 */  lui       $at, %hi(D_801565A4)
/* CA188 80133A88 A42065A4 */  sh        $zero, %lo(D_801565A4)($at)
/* CA18C 80133A8C 03E00008 */  jr        $ra
/* CA190 80133A90 27BD0020 */   addiu    $sp, $sp, 0x20
