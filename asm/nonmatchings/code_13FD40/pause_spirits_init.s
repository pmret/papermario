.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_spirits_init
/* 1406A0 8024D360 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1406A4 8024D364 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1406A8 8024D368 0080982D */  daddu     $s3, $a0, $zero
/* 1406AC 8024D36C AFBF0020 */  sw        $ra, 0x20($sp)
/* 1406B0 8024D370 AFB20018 */  sw        $s2, 0x18($sp)
/* 1406B4 8024D374 AFB10014 */  sw        $s1, 0x14($sp)
/* 1406B8 8024D378 0C039D59 */  jal       get_player_data
/* 1406BC 8024D37C AFB00010 */   sw       $s0, 0x10($sp)
/* 1406C0 8024D380 3C028027 */  lui       $v0, %hi(D_802706FC)
/* 1406C4 8024D384 244206FC */  addiu     $v0, $v0, %lo(D_802706FC)
/* 1406C8 8024D388 0000802D */  daddu     $s0, $zero, $zero
/* 1406CC 8024D38C 3C058027 */  lui       $a1, %hi(D_802706E0)
/* 1406D0 8024D390 24A506E0 */  addiu     $a1, $a1, %lo(D_802706E0)
/* 1406D4 8024D394 0040202D */  daddu     $a0, $v0, $zero
/* 1406D8 8024D398 AC400000 */  sw        $zero, ($v0)
.L8024D39C:
/* 1406DC 8024D39C 8C820000 */  lw        $v0, ($a0)
/* 1406E0 8024D3A0 00021880 */  sll       $v1, $v0, 2
/* 1406E4 8024D3A4 00651821 */  addu      $v1, $v1, $a1
/* 1406E8 8024D3A8 AC700000 */  sw        $s0, ($v1)
/* 1406EC 8024D3AC 26100001 */  addiu     $s0, $s0, 1
/* 1406F0 8024D3B0 24420001 */  addiu     $v0, $v0, 1
/* 1406F4 8024D3B4 AC820000 */  sw        $v0, ($a0)
/* 1406F8 8024D3B8 2A020007 */  slti      $v0, $s0, 7
/* 1406FC 8024D3BC 1440FFF7 */  bnez      $v0, .L8024D39C
/* 140700 8024D3C0 00000000 */   nop      
/* 140704 8024D3C4 0000802D */  daddu     $s0, $zero, $zero
/* 140708 8024D3C8 3C128027 */  lui       $s2, %hi(D_802706C0)
/* 14070C 8024D3CC 265206C0 */  addiu     $s2, $s2, %lo(D_802706C0)
/* 140710 8024D3D0 3C118025 */  lui       $s1, %hi(D_8024F8C0)
/* 140714 8024D3D4 2631F8C0 */  addiu     $s1, $s1, %lo(D_8024F8C0)
.L8024D3D8:
/* 140718 8024D3D8 0220282D */  daddu     $a1, $s1, $zero
/* 14071C 8024D3DC 8E240000 */  lw        $a0, ($s1)
/* 140720 8024D3E0 26310010 */  addiu     $s1, $s1, 0x10
/* 140724 8024D3E4 0C0B783B */  jal       func_802DE0EC
/* 140728 8024D3E8 26100001 */   addiu    $s0, $s0, 1
/* 14072C 8024D3EC AE420000 */  sw        $v0, ($s2)
/* 140730 8024D3F0 2A020007 */  slti      $v0, $s0, 7
/* 140734 8024D3F4 1440FFF8 */  bnez      $v0, .L8024D3D8
/* 140738 8024D3F8 26520004 */   addiu    $s2, $s2, 4
/* 14073C 8024D3FC 24100001 */  addiu     $s0, $zero, 1
/* 140740 8024D400 3C028025 */  lui       $v0, %hi(D_8024F9EC)
/* 140744 8024D404 2442F9EC */  addiu     $v0, $v0, %lo(D_8024F9EC)
.L8024D408:
/* 140748 8024D408 AC530010 */  sw        $s3, 0x10($v0)
/* 14074C 8024D40C 2610FFFF */  addiu     $s0, $s0, -1
/* 140750 8024D410 0601FFFD */  bgez      $s0, .L8024D408
/* 140754 8024D414 2442FFDC */   addiu    $v0, $v0, -0x24
/* 140758 8024D418 3C048025 */  lui       $a0, %hi(D_8024F9C8)
/* 14075C 8024D41C 2484F9C8 */  addiu     $a0, $a0, %lo(D_8024F9C8)
/* 140760 8024D420 0C051FCC */  jal       func_80147F30
/* 140764 8024D424 24050002 */   addiu    $a1, $zero, 2
/* 140768 8024D428 24020001 */  addiu     $v0, $zero, 1
/* 14076C 8024D42C A2620000 */  sb        $v0, ($s3)
/* 140770 8024D430 8FBF0020 */  lw        $ra, 0x20($sp)
/* 140774 8024D434 8FB3001C */  lw        $s3, 0x1c($sp)
/* 140778 8024D438 8FB20018 */  lw        $s2, 0x18($sp)
/* 14077C 8024D43C 8FB10014 */  lw        $s1, 0x14($sp)
/* 140780 8024D440 8FB00010 */  lw        $s0, 0x10($sp)
/* 140784 8024D444 03E00008 */  jr        $ra
/* 140788 8024D448 27BD0028 */   addiu    $sp, $sp, 0x28
