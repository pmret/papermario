.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dispatch_event_general
/* 1A586C 80276F8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A5870 80276F90 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A5874 80276F94 94820192 */  lhu       $v0, 0x192($a0)
/* 1A5878 80276F98 30430700 */  andi      $v1, $v0, 0x700
/* 1A587C 80276F9C 24020100 */  addiu     $v0, $zero, 0x100
/* 1A5880 80276FA0 1062000F */  beq       $v1, $v0, .L80276FE0
/* 1A5884 80276FA4 28620101 */   slti     $v0, $v1, 0x101
/* 1A5888 80276FA8 50400005 */  beql      $v0, $zero, .L80276FC0
/* 1A588C 80276FAC 24020200 */   addiu    $v0, $zero, 0x200
/* 1A5890 80276FB0 10600007 */  beqz      $v1, .L80276FD0
/* 1A5894 80276FB4 00000000 */   nop      
/* 1A5898 80276FB8 0809DBFE */  j         .L80276FF8
/* 1A589C 80276FBC 00000000 */   nop      
.L80276FC0:
/* 1A58A0 80276FC0 1062000B */  beq       $v1, $v0, .L80276FF0
/* 1A58A4 80276FC4 00000000 */   nop      
/* 1A58A8 80276FC8 0809DBFE */  j         .L80276FF8
/* 1A58AC 80276FCC 00000000 */   nop      
.L80276FD0:
/* 1A58B0 80276FD0 0C09C596 */  jal       dispatch_event_player
/* 1A58B4 80276FD4 00A0202D */   daddu    $a0, $a1, $zero
/* 1A58B8 80276FD8 0809DBFE */  j         .L80276FF8
/* 1A58BC 80276FDC 00000000 */   nop      
.L80276FE0:
/* 1A58C0 80276FE0 0C09F7A0 */  jal       dispatch_event_partner
/* 1A58C4 80276FE4 00A0202D */   daddu    $a0, $a1, $zero
/* 1A58C8 80276FE8 0809DBFE */  j         .L80276FF8
/* 1A58CC 80276FEC 00000000 */   nop      
.L80276FF0:
/* 1A58D0 80276FF0 0C09DC58 */  jal       dispatch_event_actor
/* 1A58D4 80276FF4 00000000 */   nop      
.L80276FF8:
/* 1A58D8 80276FF8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A58DC 80276FFC 03E00008 */  jr        $ra
/* 1A58E0 80277000 27BD0018 */   addiu    $sp, $sp, 0x18
