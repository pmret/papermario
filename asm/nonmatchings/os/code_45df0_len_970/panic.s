.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel panic
/* 4634C 8006AF4C 3C018009 */  lui       $at, 0x8009
/* 46350 8006AF50 AC3A4664 */  sw        $k0, 0x4664($at)
/* 46354 8006AF54 24090001 */  addiu     $t1, $zero, 1
/* 46358 8006AF58 A7490010 */  sh        $t1, 0x10($k0)
/* 4635C 8006AF5C 24090002 */  addiu     $t1, $zero, 2
/* 46360 8006AF60 A7490012 */  sh        $t1, 0x12($k0)
/* 46364 8006AF64 400A4000 */  mfc0      $t2, $8
/* 46368 8006AF68 AF4A0124 */  sw        $t2, 0x124($k0)
/* 4636C 8006AF6C 0C01ABDF */  jal       send_mesg
/* 46370 8006AF70 24040060 */   addiu    $a0, $zero, 0x60
/* 46374 8006AF74 0801AC75 */  j         osDispatchThread
/* 46378 8006AF78 00000000 */   nop      
