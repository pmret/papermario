.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_count_all
/* 13A394 80247054 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13A398 80247058 AFB00010 */  sw        $s0, 0x10($sp)
/* 13A39C 8024705C 3C108011 */  lui       $s0, 0x8011
/* 13A3A0 80247060 2610F290 */  addiu     $s0, $s0, -0xd70
/* 13A3A4 80247064 260400B4 */  addiu     $a0, $s0, 0xb4
/* 13A3A8 80247068 3C068024 */  lui       $a2, 0x8024
/* 13A3AC 8024706C 24C66FE0 */  addiu     $a2, $a2, 0x6fe0
/* 13A3B0 80247070 AFBF0014 */  sw        $ra, 0x14($sp)
/* 13A3B4 80247074 0C091293 */  jal       pause_sort_item_list
/* 13A3B8 80247078 24050080 */   addiu    $a1, $zero, 0x80
/* 13A3BC 8024707C 0000182D */  daddu     $v1, $zero, $zero
.L80247080:
/* 13A3C0 80247080 860200B4 */  lh        $v0, 0xb4($s0)
/* 13A3C4 80247084 10400005 */  beqz      $v0, .L8024709C
/* 13A3C8 80247088 00000000 */   nop      
/* 13A3CC 8024708C 24630001 */  addiu     $v1, $v1, 1
/* 13A3D0 80247090 28620080 */  slti      $v0, $v1, 0x80
/* 13A3D4 80247094 1440FFFA */  bnez      $v0, .L80247080
/* 13A3D8 80247098 26100002 */   addiu    $s0, $s0, 2
.L8024709C:
/* 13A3DC 8024709C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 13A3E0 802470A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 13A3E4 802470A4 0060102D */  daddu     $v0, $v1, $zero
/* 13A3E8 802470A8 03E00008 */  jr        $ra
/* 13A3EC 802470AC 27BD0018 */   addiu    $sp, $sp, 0x18
